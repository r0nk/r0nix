#ifndef PROCESS
#define PROCESS
#include <cpu.h>
#include <paging.h>

struct process {
	int pid;
	struct cpu_state regs;/*process registers*/
	struct pde pdir[PAGE_DIRECTORY_LENGTH]__attribute__((aligned(4096)));
};

#endif
