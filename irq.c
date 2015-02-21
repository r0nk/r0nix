#include "desc.h"
#include "stdio.h"
#include "irq.h"

/*
 * This file handles setting up the interrupts.
 */

void generic_interrupt_handler()
{
	kprint_string("INTERRUPT OCCURED!\n");
}

void initalize_idt()
{
	unsigned int addr = (unsigned int)generic_interrupt_handler;
	int high_address = addr & 0xFFFF0000;
	int low_address  = addr & 0x0000FFFF;
	int DPL = 0;//descriptor privilege level
	int P = 0;//selector present flag
	int Selector = 0;//segment selector for destination code segment
	int D = 1;//size of gate: 1=32bit;0=16bit
	int i;
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
	/* load the table into idt */
	idt_descr.size=(256*8);
	idt_descr.address=(unsigned long)idt_table;
	/* then initalize the table contents */
	initalize_idt();

	native_load_idt(&idt_descr);
}
