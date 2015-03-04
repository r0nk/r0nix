#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <multiboot.h>
#include <terminal.h>
#include <keyboard.h>
#include <stdio.h>
#include <irq.h>
#include <desc.h>
#include <gdt.h>
#include <msr.h>
#include <pic.h>
#include <block.h>
#include <init_fs.h>

#include <drivers/block/ramdisk.h>


#if defined(__linux__)
#error "You must use a cross compiler."
#endif

#if !defined(__i386__)
#error "This kernel has to be compiled with a ix86-elf compiler."
#endif

/* TODO this should be moved else-where */
/* stops the cpu forever */
void panic_hlt(){
	asm("cli");/* disable all interrupts*/
	while(1)
		asm("hlt");/* sleep till we get a interrupt */
}

void init_disk(void * mbi){
	gbda[0]=init_ramdisk(mbi);
	init_fs(gbda[0]);
}

void initalize_kernel(void * multiboot_information)
{
	/* we initalize the terminal early so we can see errors */
	initialize_terminal();

	/* hmm, not sure this should go before initing the disk...*/
	initalize_gdt();
	initalize_interrupts();
	initalize_pic(0x20,0x28);

	init_disk(multiboot_information);

	enable_keyboard();
}

/* this gets called ASAP after boot.s */
void kernel_main(void * multiboot_information)
{
	initalize_kernel(multiboot_information);
	/* run_init_shell(); TODO:this is what were shooting for. */ 
	panic_hlt();/*because run_init_shell should never return*/
}
