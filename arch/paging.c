/*the x86 specific paging functions*/
#include <paging.h>
#include <panic.h>

void invalidate_all()
{
	int i;
	for(i=0;i<1024;i++)
		flush_tlb_single(i<<22);
}

void flush_tlb_single(unsigned long addr)
{
	asm ("invlpg (%0)"::"r" (addr) : "memory");
}

void load_crx(struct pde * dir)
{
	asm("mov %0,%%eax"::"r"(dir):"%eax");
	asm("mov %%eax,%%cr3":::"%eax");

	asm("mov %%cr0,%%eax":::"%eax");
	asm("or $0x80000000,%%eax":::"%eax");
	asm("mov %%eax,%%cr0":::"%eax");
}

void enable_four_mb()
{
	asm("mov %%cr4,%%eax":::"%eax");
	asm("or $0x00000010,%%eax":::"%eax");
	asm("mov %%eax,%%cr4":::"%eax");
}
