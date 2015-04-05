#include <panic.h>
#include "scheduler.h"
#include "process.h"

/* TODO this should be an array of pointers to processes */
struct process sproct[MAX_PROCESSES];/* Scheduler PROCess Table */

int current_process;
int total_processes;

/* next_process returns the sproct index for the next process to be run */
int next_process()
{
	/* (its just round robbin for now) */
	if(current_process >= total_processes)
		return 1;
	return current_process+1;
}

void task_switch(int pid)
{
	current_process = pid;
	/*TODO*/
	panic("task_switch() nyi");
}

/* called every schedule cycle,
 * sched_tick decides which program gets to run next and starts it. 
 */
void sched_tick()
{
	task_switch(next_process());
}

void add_process()
{
	/*TODO*/
	panic("add_process() nyi");
}

void init_scheduler()
{
	current_process = 0;
	total_processes = 0;
}
