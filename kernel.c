#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "include/multiboot.h"
#include "include/terminal.h"
#include "include/keyboard.h"
#include "include/stdio.h"
#include "include/irq.h"
#include "include/desc.h"
#include "include/gdt.h"
#include "include/msr.h"
#include "include/pic.h"
#include "include/block.h"

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
