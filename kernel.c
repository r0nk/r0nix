#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminal.h"
#include "keyboard.h"
#include "stdio.h"
#include "irq.h"
#include "desc.h"
#include "gdt.h"
#include "msr.h"
#include "pic.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main()
{
	initialize_terminal();
	kprint_string("hello r0nk!\n"); 

	initalize_gdt();
	initalize_interrupts();
	initalize_pic(0x20,0x28);
	enable_keyboard();

	while(1);
}
