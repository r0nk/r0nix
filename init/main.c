#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <net/init.h>
#include <drivers/pci.h>
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
#include <exec.h>
#include <scheduler.h>

#include <drivers/ramdisk.h>

#if defined(__linux__)
#error "You must use a cross compiler."
#endif

#if !defined(__i386__)
#error "This kernel has to be compiled with a ix86-elf compiler."
#endif
/*the linker script (misc/linker.ld) defines these*/
extern int start_of_kernel;
extern int end_of_kernel;

void init_disk(struct Multiboot_Information * mbi)
{
	struct Multiboot_Module * ram_mod;
	ram_mod = (void *)mbi->mods_addr;
	root_block=init_ramdisk(ram_mod);
}

void initalize_kernel(void * multiboot_information)
{
	initialize_terminal();

	init_mm(&start_of_kernel,&end_of_kernel);

	initalize_gdt();
	initalize_interrupts();
	initalize_pic(0x20,0x28);
	enable_keyboard();

	init_disk(multiboot_information);
	init_fs();

	init_pci();
//	init_net();
	
	init_scheduler();
}

void kernel_main(void * multiboot_information)
{
	initalize_kernel(multiboot_information);
	kprintf(".r0nix\n");
	exec_inital("/r0sh");
	panic("reached end of kernel_main()");
}
