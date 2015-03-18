#include <mm.h>
#include <panic.h>

#define MAX_HEAP_ALLOC 1024
#define HEAP_BLOCK_SIZE 1024
static void * mm_heap;
static unsigned long long mm_heapsize;
static unsigned int mm_heap_bitmap;

void init_mm(void * heap,unsigned long long heapsize)
{
	mm_heap = heap;
	mm_heap_bitmap = 0;
	mm_heapsize = heapsize;

	q=kmalloc(1000);
	q_size=0;
}

void * kmalloc(int size)
{
	int i;

	if(mm_heap_bitmap>=0xff)
		panic("ran out of heap space.");

	if(size>=HEAP_BLOCK_SIZE)
		panic("tried to alloc > max alloc");

	/*find the next free spot in the bitmap*/
	for(i=0;i<16;i++)
		if(!(mm_heap_bitmap & (1<<i)))
			break;

	mm_heap_bitmap|=(1<<i);
	return (mm_heap+(i*HEAP_BLOCK_SIZE));
}

void free(void * p)
{
	if(p<mm_heap || p>(mm_heap+mm_heapsize))
		panic("free value out of range");
	int i = ((p-mm_heap)/HEAP_BLOCK_SIZE);
	mm_heap_bitmap^=i;
}
