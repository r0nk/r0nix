#include <panic.h>
#include <scheduler.h>
#include <fork.h>

/*allocate new pages for a process clone*/
void change_pages(struct process *clone)
{
	/*TODO*/
	clone++;
}

/*TODO FIXME doesn't use new pages, all around hacky and bad*/
int fork(){
	int pid;
	total_processes++;
	if(total_processes>MAX_PROCESSES)
		panic("fork:total processes > max");
	sched_procs[total_processes]=sched_procs[current_process];
	/*set the return value for the clone to 0*/
	sched_procs[total_processes].regs.eax=0;
	pid=total_processes;
	return pid;
}
