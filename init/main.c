#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

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
	struct Multiboot_Module * mm;
	mm = (void *)mbi->mods_addr;
	gbda[0]=init_ramdisk(mm);
	init_fs(0);
}

void test_fs()
{
	kprintf("Testing Filesystem...\n");
	int f=open("/MAGICAL_FILE");//this appears to never return 
	char a[9];
	int c = read(f,a,1);
	kprintf("First char :%x\n",c);
}

void test_mm(){
	char * p1 = kmalloc(10);
	char * p2 = kmalloc(10);
	p1[0]='h';
	p1[1]='e';
	p1[2]='l';
	p1[3]='l';
	p1[4]='o';

	p2[0]='w';
	p2[1]='o';
	p2[2]='r';
	p2[3]='l';
	p2[4]='d';

	kprintf("p1:%s,p2:%s\n",p1,p2);
	free(p1);
	free(p2);
}


void initalize_kernel(void * heap,void * multiboot_information)
{
	/* we initalize the terminal early so we can see errors */
	initialize_terminal();
	kprintf("Hello r0nk!\n");

	init_mm(heap,16384);
	test_mm();

	/* hmm, not sure this should go before initing the disk...*/
	initalize_gdt();
	initalize_interrupts();
	initalize_pic(0x20,0x28);

	init_disk(multiboot_information);
	init_fs();

	test_fs();

	enable_keyboard();
}

/* this gets called ASAP after boot.s */
void kernel_main(void * heap,void * multiboot_information)
{
	initalize_kernel(heap,multiboot_information);
	/* run_init_shell(); TODO:this is what were shooting for. */ 

	panic("reached end of kernel main");
}
