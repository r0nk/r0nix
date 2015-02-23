#ifndef MSR
#define MSR

inline unsigned long long read_msr(unsigned int msr)
{
	unsigned long long val;

	asm volatile("rdmsr" :"=A" (val) : "c" (msr));
	return val;
}

#endif
