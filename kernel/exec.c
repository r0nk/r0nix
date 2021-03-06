#include <fs.h>
#include <exec.h>
#include <kprint.h>
#include <panic.h>
#include <time_stamp.h>
#include <mm.h>
#include <paging.h>
#include <scheduler.h>

#include "elf/elf.h"

#define STACK_POINTER 0x08000000

void setup_pages(struct process * proc,struct elf32_phdr phdr,void * proc_page)
{
	int i;
	for(i=0;i<PAGE_DIRECTORY_LENGTH;i++)
		proc->pdir[i].present=0;
	proc->pdir[k_page_index] = kpd[k_page_index];/* keep kernel in memory */
	int pi = (int)phdr.p_vaddr>>22;/* page index for process */
	proc->pdir[pi]=create_pde();
	proc->pdir[pi].frame_addr = ((uint32_t)proc_page)>>22;
	proc->pdir[pi].present=1;

	void * stack = kmalloc(0x9001);
	proc->pdir[STACK_POINTER>>22]=create_pde();
	proc->pdir[STACK_POINTER>>22].frame_addr = ((uint32_t)stack)>>22;
	proc->pdir[STACK_POINTER>>22].present = 1;
}

void load_registers(struct process * proc, uint32_t entry_point)
{
	proc->regs.edi=0;
	proc->regs.esi=0;
	proc->regs.ebp=0;
	proc->regs.esp=STACK_POINTER+0x9001;
	proc->regs.ebx=0;
	proc->regs.edx=0;
	proc->regs.ecx=0;
	proc->regs.eax=0;
	proc->regs.eip=entry_point;
	proc->regs.cs=0x8;
	proc->regs.eflags=0x202;
}

/* parse the executable file and store it into the process */
void file_to_process(char * path,struct process * proc)
{
	int fd  = open(path);
	if(fd<1)
		panic(" file_to_process: fd<1 ");
	struct elf32_hdr hdr = get_elf_hdr(fd);
	struct elf32_phdr phdr = get_elf_phdr(fd);

	if(hdr.e_phnum>1)
		panic(" file_to_process: multi-segment program header,nyi ");

	void * proc_page = kmalloc(phdr.p_memsz);

	setup_pages(proc,phdr,proc_page);

	/* this sets the fd read head to zero */
	close(fd);
	fd = open(path);

	/* read in the whole executable file to its page */
	if(read(fd,proc_page,phdr.p_memsz)!=(int)phdr.p_memsz)
		panic("file_to_process: not enough bytes read from file");
	
	load_registers(proc,hdr.e_entry);
}


/* This creates the inital process (which always has pid 1) */
void exec_inital(char * path)
{
	struct process * p1;
	p1 = get_free_process();
       	file_to_process(path,p1);
	sched_tick();
}

void exec(char * path)
{
	file_to_process(path,&sched_procs[current_process]);
}
