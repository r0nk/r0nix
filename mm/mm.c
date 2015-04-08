#include <mm.h>
#include <panic.h>
#include <paging.h>
#include <kprint.h>

#define MAX_ALLOC 4194304
#define HEAP_BLOCK_SIZE 4194304

void init_mm(void * kernel_start,void * kernel_end)
{
	init_paging(kernel_start,kernel_end);
	q_size=0;
}

inline void * next_free_spot()
{
	unsigned int i;
	for(i=3;i<PAGE_DIRECTORY_LENGTH;i++){
		if(kpd[i].present==0){
			kpd[i].present=1;
			kprintf("malloced: %i,returning %x\n",i,i<<22);
			return (void *) (i<<22);/*this is a bit tricky*/
		}
	}
	return 0;
}

void * kmalloc(int size)
{
	void * ret;
	if(size>=HEAP_BLOCK_SIZE)
		panic("mm: tried to alloc > max alloc");
	ret = next_free_spot();
	if(!ret)
		panic("mm: couldn't find free spot (possibly out of them)");
	flush_tlb_single((unsigned long)ret);
	return ret;
}

void free(void * p)
{
	int i = (int)p>>22;/*index in the page directory for the pointer p*/
	kpd[i].present=0;
}
