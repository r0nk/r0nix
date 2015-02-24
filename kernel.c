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


void fake_int(){
	asm("int $2");
}

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
	initalize_interrupts();
	kprint_string("hello r0nk!\n\n");

	kprint_string("idt_table:");
	kprint_int((unsigned int)idt_table);
	kprint_string("\n");

	asdf(0);
	asdf(1);
	asdf(2);
	asdf(3);

	kprint_string("generic interrupt handler:");
	kprint_int((unsigned long)generic_interrupt_handler);
	kprint_string("\n");

	fake_int();
}
