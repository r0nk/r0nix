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

void jump(struct cpu_state state)
{
	/*
	 * We can't just popa and then iret, because popa moves our stack.
	 * So, we have to manually push the return pointer onto the new stack,
	 * then popa-iret.
	 */
	uint32_t * stack = (void *)state.esp;
	/*push the state onto the stack*/
	*(--stack) = 0x10;
	*(--stack) = state.esp;
	*(--stack) = state.eflags;
	*(--stack) = state.cs;
	*(--stack) = state.eip;
	*(--stack) = state.eax;
	*(--stack) = state.ecx;
	*(--stack) = state.edx;
	*(--stack) = state.ebx;
	*(--stack) = state.esp;/*doesn't get pop-ped*/
	*(--stack) = state.ebp;
	*(--stack) = state.esi;
	*(--stack) = state.edi;

	asm("mov %%eax,%%esp;\n\t"
			"popa;\n\t"::"a"(stack));
	asm("iret;\n\t");
	panic("jump: reached after iret call,should never occur.");
}

void task_switch(int index)
{
	current_process = index;
	load_crx(sched_procs[index].pdir);
	jump(sched_procs[index].regs);
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
	int pid;
	total_processes++;
	if(total_processes>MAX_PROCESSES)
		panic("total processes > max");
	sched_procs[total_processes]=p;
	pid=total_processes;/*<-- TODO: this isn't quite right yet */
	p.pid=total_processes;
	return pid;
}

void init_scheduler()
{
	current_process = 0;
	total_processes = 0;
}
