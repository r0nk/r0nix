#include "desc.h"
#include "stdio.h"
#include "irq.h"

/*
 * This file handles setting up the interrupts.
 */

void generic_interrupt_handler()
{
	kprint_string("INTERRUPT OCCURED!\n");
	while(1);//just hang for now
}

void initalize_idt()
{
	unsigned long addr = (unsigned long)generic_interrupt_handler;
	int high_address = addr & 0xFFFF0000;
	int low_address  = addr & 0x0000FFFF;
	int DPL = 0;//descriptor privilege level
	int P = 0;//selector present flag
	int Selector = 0;//segment selector for destination code segment
	int D = 1;//size of gate: 1=32bit;0=16bit
	int i;
	kprint_string("\n h:\n");
	kprint_int(high_address);
	kprint_string("\n l:\n");
	kprint_int(low_address);
	for(i=0;i<256;i++){
		idt_table[i].a=high_address;
		idt_table[i].a+=P<<15;
		idt_table[i].a+=DPL<<13;
		idt_table[i].a+=D<<11;
		idt_table[i].a+=0x0300;

		idt_table[i].b=low_address;
		idt_table[i].b+=Selector<<16;
	}
}

void initalize_interrupts()
{
	/* initalize the table contents */
	initalize_idt();
	idt_descr.size=(256*8)-1;
	idt_descr.address=(unsigned int)idt_table;

	load_idt(&idt_descr);
}
