#include <panic.h>
#include <kprint.h>
#include "paging.h"

/*TODO:The inline here should probaly be moved to r0nix/arch/ */
static void load_crx(struct pde * dir)
{
	asm("mov %0,%%eax"::"r"(dir):"%eax");
	asm("mov %%eax,%%cr3":::"%eax");

	asm("mov %%cr0,%%eax":::"%eax");
	asm("or $0x80000000,%%eax":::"%eax");
	asm("mov %%eax,%%cr0":::"%eax");
}

/*TODO:The inline here should probaly be moved to r0nix/arch/ */
static void enable_four_mb()
{
	asm("mov %%cr4,%%eax":::"%eax");
	asm("or $0x00000010,%%eax":::"%eax");
	asm("mov %%eax,%%cr4":::"%eax");
}

static void init_kpd(void * kernel_start, void * kernel_end)
{
	int i;
	for(i=0;i<PAGE_DIRECTORY_LENGTH;i++){
		kpd[i].reserved = 0;
		kpd[i].addr_bits = 0;
		kpd[i].pat = 0;/*<-- this _might_ not be right...*/
		kpd[i].ignored = 0;
		kpd[i].global = 0;
		kpd[i].page_size = 1;
		kpd[i].dirty = 0;
		kpd[i].accessed = 0;
		kpd[i].cache_disable= 1;
		kpd[i].write_through=0;
		kpd[i].super=0;
		kpd[i].read_write=1;
		kpd[i].present=0;
		kpd[i].frame_addr=i;
	}
	if((kernel_end-kernel_start)>PAGE_SIZE)
		panic("kernel bigger then a single page");
	int ki = ((unsigned int)kernel_start)/PAGE_SIZE;
	kpd[ki].present=1;/* let paging know the kernel space is allocated */
}

#if 0
void trace_kpd(){
	int i,s;
	kprintf("kpd:%x\n",kpd);
	for(i=0;i<12;i++){
		for(s=0;s<19000;s++);/*nooby sleep*/
		kprintf(" kpd[%i]:%x\n",i,kpd[i]);
	}
}
#endif

void init_paging(void * kernel_start, void * kernel_end)
{
	init_kpd(kernel_start,kernel_end);
	enable_four_mb();
	load_crx(kpd);
}
