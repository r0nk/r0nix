/*the x86 specific paging functions*/
#include <paging.h>

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
