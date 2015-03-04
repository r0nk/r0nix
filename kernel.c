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

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void * multiboot_information)
{
	initialize_terminal();
	kprint_string("hello r0nk!\n"); 

	parse_multiboot(multiboot_information);

	initalize_gdt();
	initalize_interrupts();
	initalize_pic(0x20,0x28);
	enable_keyboard();

	write_to_block_device(0,20,0xde);
	write_to_block_device(0,21,0xed);
	write_to_block_device(0,22,0xbe);
	write_to_block_device(0,23,0xef);

	while(1)
		asm("hlt");
}
