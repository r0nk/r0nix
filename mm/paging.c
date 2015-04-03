#include <panic.h>
#include <kprint.h>
#include "paging.h"

/*just one, identity map, directory for the whole kernel for now*/
struct pde kpd[PAGE_DIRECTORY_LENGTH]__attribute__((aligned(4096)));

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

static void init_kpd()
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
		kpd[i].present=1;
		kpd[i].frame_addr=i;
	}
}

void trace_kpd(){
	int i,s;
	kprintf("kpd:%x\n",kpd);
	for(i=0;i<12;i++){
		for(s=0;s<19000;s++);/*nooby sleep*/
		kprintf(" kpd[%i]:%x\n",i,kpd[i]);
	}
}

void init_paging()
{
	init_kpd();
	enable_four_mb();
	//trace_kpd();
	load_crx(kpd);
}
