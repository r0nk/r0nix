#include <fs.h>
#include <exec.h>
#include <kprint.h>
#include <panic.h>
#include <time_stamp.h>
#include <mm.h>
#include <scheduler.h>

#include "elf/elf.h"

void setup_pages(struct process * proc,struct elf32_phdr phdr,void * proc_page)
{
	int pi = (phdr.p_vaddr<<22);/* page index for process */
	/* keep the kernel mapped in memory */
	proc->pdir[k_page_index] = kpd[k_page_index];
	/* figure out what page the program is asking for */
	proc->pdir[pi].frame_addr = ((int)proc_page)>>21;
	proc->pdir[pi].read_write = 1;
	proc->pdir[pi].page_size = 1;
	proc->pdir[pi].present = 1;
}

/* parse the executable file and store it into the returned process */
struct process file_to_process(char * path)
{
	struct process proc;
	int fd  = open(path);
	if(fd<1)
		panic(" file_to_process: fd<1 ");
	struct elf32_hdr hdr = get_elf_hdr(fd);
	struct elf32_phdr phdr = get_elf_phdr(fd);

	if(hdr.e_phnum>1)
		panic(" file_to_process: multi-segment program header,nyi ");

	void * proc_page = kmalloc(phdr.p_memsz);

	setup_pages(&proc,phdr,proc_page);

	/* this set the fd read head to zero */
	close(fd);
	fd = open(path);

	/* read in the whole executable file to its page */
	if(read(fd,proc_page,phdr.p_memsz)!=phdr.p_memsz)
		panic("file_to_process: not enough bytes read from file");

	/* set up the registers */
	proc.regs.edi=0;
	proc.regs.esi=0;
	proc.regs.ebp=0;
	proc.regs.esp=0;/*TODO*/
	proc.regs.ebx=0;
	proc.regs.edx=0;
	proc.regs.ecx=0;
	proc.regs.eax=0;
	proc.regs.eip=hdr.e_entry;
	proc.regs.cs=0;/* TODO we need to get the current cs */
	proc.regs.eflags=0x202;

	return proc;
}

/* This creates the inital process (which always has pid 1) */
void exec_inital(char * path)
{
	struct process p1 = file_to_process(path);
	add_process(p1);
}

void exec(char * path)
{
	replace_current_process(file_to_process(path));
}
