#include <panic.h>
#include <kprint.h>
#include <scheduler.h>
#include <mm.h>
#include <fork.h>
#include <paging.h>

void replace_page(struct pde * dir,int pi){
	uint8_t * replaced_page;/*the processes page to replace*/
	uint8_t * k_page;/*the kernels replacement page*/
	uint8_t * tmp_page;/*the processes (dir) tmp page*/
	int tmp_pi;/*the index of the processes tmp page*/

	k_page=kmalloc(PAGE_SIZE-1);
	tmp_pi = next_free_spot(dir);

	map(dir,tmp_pi,k_page);

	tmp_page = (void *) (tmp_pi<<22);
	replaced_page = (void *) (pi<<22);

	copy_page(replaced_page,tmp_page);

	/*store the new page in the old page's spot*/
	dir[pi].frame_addr=(unsigned int)tmp_page>>22;

	dir[tmp_pi].present=0;/*free the dir tmp page*/
}

/*allocate and copy new pages for a process clone*/
void get_new_pages(struct process * proc)
{
	int i;
	for(i=0;i<PAGE_DIRECTORY_LENGTH;i++){
		if(i==k_page_index)
			continue;/*don't replace the kernel*/
		if(proc->pdir[i].present)
			replace_page(proc->pdir,i);
	}
}

/*TODO FIXME all around hacky and bad*/
int fork(){
//	kprintf("fork called\n");
//	load_crx(kpd); 
	struct process * proc = get_free_process();
	(*proc)=sched_procs[current_process];
	get_new_pages(proc);
	/*set the return value for the clone to 0*/
	sched_procs[total_processes].regs.eax=0;
	return total_processes;
}
