#include <panic.h>
#include <kprint.h>
#include <scheduler.h>
#include <mm.h>
#include <fork.h>
#include <paging.h>

void replace_page(struct pde * dir,int pi){
	uint8_t * page_to_replace;/*the processes page to replace*/
	uint8_t * k_page;/*the kernels new page*/
	uint8_t * tmp_page;/*the processes (dir) tmp page*/
	int tmp_pi;/*the index of the processes tmp page*/

	k_page=kmalloc(PAGE_SIZE-1);
	tmp_pi = next_free_spot(dir);

	map(dir,tmp_pi,k_page);

	tmp_page = (void *) (tmp_pi<<22);
	page_to_replace = (void *) (pi<<22);

	copy_page(page_to_replace,tmp_page);

	/*store the new page in the old page's spot*/
	dir[pi].frame_addr=(unsigned int)k_page>>22;

	dir[tmp_pi].present=0;/*free the dir tmp page*/
}

/*allocate and copy new pages for a process clone*/
void get_new_pages(struct process * proc)
{
	int i;
	load_crx(proc->pdir);
	for(i=0;i<PAGE_DIRECTORY_LENGTH;i++){
		if(i==k_page_index)
			continue;/*don't replace the kernel*/
		if(proc->pdir[i].present)
			replace_page(proc->pdir,i);
	}
	load_crx(sched_procs[current_process].pdir);
}

int fork(){
	struct process * clone = get_free_process();
	(*clone)=sched_procs[current_process];
	get_new_pages(clone);
	clone->regs.eax=0;
	return clone->pid;
}
