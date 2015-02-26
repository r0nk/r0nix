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
	int P = 1;//selector present flag
	int Selector = 8<<3;//segment selector for destination code segment. 
	int D = 1;//size of gate: 1=32bit;0=16bit
	int type=14;
	int i;
	kprint_string("\n h:\n");
	kprint_int(high_address);
	kprint_string("\n l:\n");
	kprint_int(low_address);
	for(i=0;i<256;i++){
		//.b is e2 in qemu
		//1<<12 is causin probs in e2
		idt_table[i].b=high_address;
		idt_table[i].b|=P<<15;
		idt_table[i].b|=DPL<<13;
		idt_table[i].b|=D<<11;
		idt_table[i].b|=type<<8;

		idt_table[i].a=low_address;
		idt_table[i].a|=Selector<<16;

		//FIXME the gate appears to be getting type from .b
		//this is a problem with the selector variable then.
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
