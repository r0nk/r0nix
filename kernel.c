#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminal.h"
#include "stdio.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main()
{
	terminal_initialize();
	kprint_string("hello r0nk!\n");
	unsigned int beef = 0xDEADBEEF;
	unsigned int * dead = &beef;
	kprint_int(0xC0DEC0DE);
	kprint_string("\n");
	kprint_int(*dead);
	kprint_string("\n");
	kprint_int((unsigned int)dead);
}
