#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminal.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main()
{
	terminal_initialize();
	terminal_writestring("Hello, r0nk!\n");
}
