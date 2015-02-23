#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminal.h"
#include "stdio.h"
#include "irq.h"
#include "desc.h"
#include "msr.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void asdf(int i){
	kprint_string("idt_table[");
	kprint_int(i);
	kprint_string("]: ");
	kprint_int(idt_table[i].a);
	kprint_string(" ");
	kprint_int(idt_table[i].b);
	kprint_string("\n");
}

void kernel_main()
{
	terminal_initialize();
	kprint_string("hello r0nk!\n");
}
