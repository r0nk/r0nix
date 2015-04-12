#ifndef CPU
#define CPU
#include <stdint.h>
#include <kprint.h>

/* a cpu_state gets pushed onto the stack on every interrupt */
struct cpu_state{
	/*pushad registers (in order)*/
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t esp;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;
	/*interrupt vector*/
	uint32_t vector;
	/*pushed by the interrupt*/
	uint32_t eip;
	uint32_t cs;
	uint32_t eflags;
};

#endif
