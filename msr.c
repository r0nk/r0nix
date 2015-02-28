#include "include/msr.h"

unsigned long long read_msr(unsigned int msr)
{
	unsigned long long val;
	asm volatile("rdmsr" :"=A" (val) : "c" (msr));
	return val;
}
