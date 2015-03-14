#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <string.h>
#include <kprint.h>
#include <panic.h>
#include <multiboot.h>
#include <terminal.h>
#include <keyboard.h>
#include <irq.h>
#include <desc.h>
#include <gdt.h>
#include <msr.h>
#include <pic.h>
#include <block.h>
#include <fs.h>
#include <mm.h>

#include <drivers/block/ramdisk.h>

#if defined(__linux__)
#error "You must use a cross compiler."
#endif

#if !defined(__i386__)
#error "This kernel has to be compiled with a ix86-elf compiler."
#endif

/* TODO this should probably be moved elsewhere. */
void init_disk(struct Multiboot_Information * mbi)
{
	struct Multiboot_Module * ram_mod;
	ram_mod = (void *)mbi->mods_addr;
	gbda[0]=init_ramdisk(ram_mod);
}

void test_fs()
{
	char * path = strdup("/The Raven");
	kprintf("Testing Filesystem...\n");
	kprintf("path:%s\n",path);
	int f=open(path);//this appears to never return 
	free(path);
	char a[55];
	read(f,a,54);
	a[54]=0;
	kprintf("in file:%s\n",a);
}

void initalize_kernel(void * heap,void * multiboot_information)
{
	/* we initalize the terminal early so we can see errors */
	initialize_terminal();
	kprintf("Hello r0nk!\n");

	init_mm(heap,16384);

	/* hmm, not sure this should go before initing the disk...*/
	initalize_gdt();
	initalize_interrupts();
	initalize_pic(0x20,0x28);

	init_disk(multiboot_information);
	init_fs();

	test_fs();

	enable_keyboard();
}

/* this gets called right after boot.s */
void kernel_main(void * heap,void * multiboot_information)
{
	initalize_kernel(heap,multiboot_information);
	/* run_init_shell(); TODO:this is what were shooting for. */ 
	panic("reached end of kernel_main");
}
