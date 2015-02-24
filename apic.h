#ifndef APIC
#define APIC
#include "msr.h"

inline void * apic_base_address(){
	unsigned long msr = read_msr(0x1b);//0x1b is for APIC
	msr = (msr & 0xfffff000);/*TODO:this doesn't account for high bits*/
	return (void *)(msr);
}

inline void * apic_register_address(int offset){
	return apic_base_address() + offset;
}

inline void write_apic_register(unsigned int val,int offset){
	unsigned int * a = (unsigned int *) apic_register_address(offset);
	(*a)=val;
}

inline unsigned int read_apic_register(int offset){
	unsigned int * ar = apic_register_address(offset);
	return (*ar);
}

#endif
