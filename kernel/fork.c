#include <panic.h>
#include <scheduler.h>
#include <fork.h>

struct process clone_process(struct process orig)
{
	struct process clone = orig;
	/* copy-paste all the clones pages */
	/* TODO FIXME right now, we just let the two processes overwrite 
	 * eachother. Obviously terribad, so fix this asap.
	 */
	return clone;
}

/*TODO struct process is too big to throw around the stack*/
int fork(){
	int pid;
	struct process clone = clone_process(sched_procs[current_process]);
	clone.regs.eax=0;/*set the return value for the clone to 0*/
	pid = add_process(clone);
	return pid;
}
