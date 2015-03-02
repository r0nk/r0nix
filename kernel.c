#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "include/terminal.h"
#include "include/keyboard.h"
#include "include/stdio.h"
#include "include/irq.h"
#include "include/desc.h"
#include "include/gdt.h"
#include "include/msr.h"
#include "include/pic.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void * multiboot_information)
{
	initialize_terminal();
	kprint_int((unsigned int)multiboot_information);
	kprint_string("hello r0nk!\n"); 
	kprint_int((unsigned int)multiboot_information);

	initalize_gdt();
	initalize_interrupts();
	initalize_pic(0x20,0x28);
	enable_keyboard();

	while(1)
		asm("hlt");
}
