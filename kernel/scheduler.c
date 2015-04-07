#include <panic.h>
#include <kprint.h>
#include <paging.h>
#include <scheduler.h>

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

int add_process(struct process p)
{
	total_processes++;
	if(total_processes>MAX_PROCESSES)
		panic("total processes > max");
	sched_procs[total_processes]=p;
	p.pid=total_processes;
	return p.pid;
}

void init_scheduler()
{
	current_process = 0;
	total_processes = 0;
}
