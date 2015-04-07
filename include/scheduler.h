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

/* this should be an array of pointers to processes */
struct process sched_procs[MAX_PROCESSES];/* all the current processes */

/* current_process is an index into the sched_procs array, rather then a PID */
int current_process;
int total_processes;

void sched_tick();
void replace_current_process(struct process replacer);
int add_process(struct process p);
void init_scheduler();

#endif
