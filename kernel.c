#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminal.h"
#include "stdio.h"
#include "irq.h"
#include "desc.h"
#include "gdt.h"
#include "msr.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif


void fake_int(){
	asm("int $42");
}

void print_idt_entry(int i){
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
	initalize_gdt();
	initalize_interrupts();
	kprint_string("hello r0nk!\n\n");

	kprint_string("idt_table:");
	kprint_int((unsigned int)idt_table);
	kprint_string("\n");

	print_idt_entry(0);
	print_idt_entry(42);

	kprint_string("generic interrupt handler:");
	kprint_int((unsigned long)generic_interrupt_handler);
	kprint_string("\n");

	//while(1);
	fake_int();
}
