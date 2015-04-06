#include <panic.h>
#include <paging.h>
#include <scheduler.h>

/* this should be an array of pointers to processes */
struct process sched_procs[MAX_PROCESSES];/* all the current processes */

/* current_process is an index into the sched_procs array, rather then a PID */
int current_process;
int total_processes;

/* next_process returns the sched_procs index for the next process to be run */
int next_process()
{
	if(current_process >= total_processes)
		return 1;
	/* (its just round robbin for now) */
	return current_process+1;
}

void task_switch(int index)
{
	current_process = index;
	load_crx(sched_procs[index].pdir);
	panic("task_switch() nyi");
}

/* called every schedule cycle,
 * sched_tick decides which program gets to run next and starts it. 
 */
void sched_tick()
{
	task_switch(next_process());
}

void replace_current_process(struct process replacer)
{
	sched_procs[current_process]=replacer;
}

void add_process(struct process p)
{
	total_processes++;
	if(total_processes>MAX_PROCESSES)
		panic("total processes > max");
	sched_procs[total_processes]=p;
}

void init_scheduler()
{
	current_process = 0;
	total_processes = 0;
}
