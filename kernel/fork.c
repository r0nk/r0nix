#include <panic.h>
#include <kprint.h>
#include <scheduler.h>
#include <mm.h>
#include <fork.h>
#include <paging.h>

/*allocate new pages for a process clone*/
void get_new_pages()
{
	kprintf("get new pages\n");
	long i;
	int pi=total_processes;
	uint8_t * np,* p;
	for(i=3;i<PAGE_DIRECTORY_LENGTH;i++){
		if(i==k_page_index)
			continue;
		if(sched_procs[pi].pdir[i].present){
			np=kmalloc(PAGE_SIZE-1);
			p=(uint8_t *)(sched_procs[pi].pdir[i].frame_addr<<22);
			copy_page(p,np);
			sched_procs[pi].pdir[i].frame_addr=(unsigned int)np>>22;
		}
	}
}

/*TODO FIXME all around hacky and bad*/
int fork(){
	kprintf("fork called\n");
	load_crx(kpd); 
	total_processes++;
	if(total_processes>MAX_PROCESSES)
		panic("fork:total processes > max");
	sched_procs[total_processes]=sched_procs[current_process];
	get_new_pages();
	/*set the return value for the clone to 0*/
	sched_procs[total_processes].regs.eax=0;
	return total_processes;
}
