#include <panic.h>
#include <kprint.h>
#include <paging.h>
#include <stdint.h>

struct pde create_pde()
{
	struct pde pde;
	pde.reserved = 0;
	pde.addr_bits = 0;
	pde.pat = 0;/*<-- this _might_ not be right...*/
	pde.ignored = 0;
	pde.global = 0;
	pde.page_size = 1;
	pde.dirty = 0;
	pde.accessed = 0;
	pde.cache_disable= 1;
	pde.write_through=0;
	pde.super=0;
	pde.read_write=1;
	pde.present=0;
	pde.frame_addr=0;
	return pde; 
}

void trace_kpd()
{
	int i;
	kprintf("kpd:%x\n",kpd);
	for(i=0;i<3;i++){
		kprintf(" kpd[%i]:%x\n",i,kpd[i]);
	}
}

static void init_kpd(void * kernel_start, void * kernel_end)
{
	int i;
	for(i=0;i<PAGE_DIRECTORY_LENGTH;i++){
		kpd[i] = create_pde();
		kpd[i].frame_addr=i;
	}
	if((kernel_end-kernel_start)>PAGE_SIZE)
		panic("kernel bigger then a single page, nyi");
	k_page_index = ((unsigned int)kernel_start)/PAGE_SIZE;
	kpd[k_page_index].present=1;/* allocate the kernel-space */
}

void map(struct pde * dir, int i, void * addr)
{
	dir[i].present=1;
	dir[i].frame_addr=((unsigned int)addr)>>22;
}

/* copy-paste all the contents of a page onto another */
void copy_page(uint8_t * source, uint8_t * destination)
{
	int i;

	flush_tlb_single((unsigned long)source);
	flush_tlb_single((unsigned long)destination);

	if(!source||!destination)
		panic("copy_page: null page pointer"); 

	for(i=0;i<PAGE_SIZE;i++)
		destination[i]=source[i];
}

int next_free_spot(struct pde * dir)
{
	int i;
	for(i=0;i<PAGE_DIRECTORY_LENGTH;i++)
		if(!dir[i].present)
			return i;
	panic("free spot not found");
	return -1;
}

void init_paging(void * kernel_start, void * kernel_end)
{
	init_kpd(kernel_start,kernel_end);
	enable_four_mb();
	load_crx(kpd);
}
