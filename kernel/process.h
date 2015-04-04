#ifndef PROCESS
#define PROCESS

struct process {
	struct cpu_state regs;/*process registers*/
	struct page_directory pdir;
}

#endif
