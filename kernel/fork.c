#include <panic.h>
#include <kprint.h>
#include <scheduler.h>
#include <mm.h>
#include <fork.h>
#include <paging.h>

/*allocate new pages for a process clone*/
void get_new_pages(struct process *clone)
{
	kprintf("get new pages\n");
	long i;
	unsigned long j;
	char * np,* p;
//	load_crx(kpd); This destroys our dear stack
	for(i=3;i<PAGE_DIRECTORY_LENGTH;i++){
		if(i==k_page_index)
			continue;
		if(clone->pdir[i].present==1){/*then swap out this page*/
			kprintf("i = %i\n",i);
			kprintf("clone->pdir[i].present:%i\n",
				clone->pdir[i].present==1);
			np=kmalloc(PAGE_SIZE-1);
			kprintf("clone->pdir[i].frame_addr:%x\n",
					clone->pdir[i].frame_addr);
			p=(char *)(clone->pdir[i].frame_addr<<22);
			kprintf(" np=%x , p=%x\n",np,p);
			/*copy all the contents*/
			for(j=0;j<PAGE_SIZE;j++){
				np[j]=p[j];
				kprintf(".");
			}
			clone->pdir[i].frame_addr=(unsigned int)np<<22;
		}
	}
}

/*TODO FIXME doesn't use new pages, all around hacky and bad*/
int fork(){
	kprintf("fork called\n");
	int pid;
	total_processes++;
	if(total_processes>MAX_PROCESSES)
		panic("fork:total processes > max");
	sched_procs[total_processes]=sched_procs[current_process];
	get_new_pages(&sched_procs[total_processes]);
	/*set the return value for the clone to 0*/
	sched_procs[total_processes].regs.eax=0;
	pid=total_processes;
	return pid;
}
