#include <mm.h>
#include <panic.h>
#include <paging.h>
#include <kprint.h>

#define MAX_ALLOC 4194304
#define HEAP_BLOCK_SIZE 4194304

void test_mm();

void init_mm(void * kernel_start,void * kernel_end)
{
	init_paging(kernel_start,kernel_end);
	q_size=0;
//	test_mm();
}


/*FIXME kmalloc appers to fail after loading another segment*/
void * kmalloc(int size)
{
	void * ret;
	int i;
	if(size>=HEAP_BLOCK_SIZE)
		panic("mm: tried to alloc > max alloc");
	i = next_free_spot(kpd);
	kpd[i].present=1;
	ret = (void *) (i<<22);
	flush_tlb_single((unsigned long)ret);
	return ret;
}

void free(void * p)
{
	kprintf("freeing %x\n",p);
	int i = (int)p>>22;/*index in the page directory for the pointer p*/
	kpd[i].present=0;
}

//#if 0
void test_mm()
{
	kprintf("testing memory");
	char *a,*b,*c,*d,*e,*f;
	a=kmalloc(500);
	b=kmalloc(500);
	c=kmalloc(500);
	d=kmalloc(500);
	e=kmalloc(500);
	f=kmalloc(500);
	load_crx(kpd);
	(*a)++;
	(*b)++;
	(*c)++;
	(*d)++;
	(*e)++;
	(*f)++;
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
}
//#endif
