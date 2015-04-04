#include <mm.h>
#include <panic.h>
#include "paging.h"

#define MAX_ALLOC 4194304
#define HEAP_BLOCK_SIZE 4194304

void init_mm()
{
	init_paging();

	/*queue initalization TODO should be moved */
	q=kmalloc(1000);
	q_size=0;
}

void * kmalloc(int size)
{
	int i;
	void * ret;

	panic("kmalloc NYI");

/*
	if(TODO)
		panic("ran out of heap space.");
*/

	if(size>=HEAP_BLOCK_SIZE)
		panic("tried to alloc > max alloc");

	/*TODO find the next free spot in the bitmap here*/

	return ret;
}

void free(void * p)
{
	/*TODO*/
	panic("free NYI");
}
