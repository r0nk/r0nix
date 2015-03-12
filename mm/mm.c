#include <mm.h>
#include <panic.h>

static void * mm_heap;
static unsigned long long mm_heapsize;
static unsigned int mm_heap_bitmap;

void init_mm(void * heap,unsigned long long heapsize){
	mm_heap = heap;
	mm_heap_bitmap=0;
}

void * kmalloc(int dont_care)/*TODO care.*/
{
	if(mm_heap_bitmap==0xff){
		panic("Ran out of heap space.");
	}
	/*TODO find the next free spot and return it*/
}

void free(void * p)
{
	/* set p-bit in bitmap to zero */
}
