#ifndef SCHEDULER
#define SCHEDULER
#include <cpu.h>
#include <paging.h>

struct process {
	int pid;
	struct cpu_state regs;/*process registers*/
	struct pde pdir[PAGE_DIRECTORY_LENGTH]__attribute__((aligned(4096)));
};

#define MAX_PROCESSES 100

void sched_tick();
void replace_current_process(struct process replacer);
void add_process(struct process p);
void init_scheduler();

#endif
