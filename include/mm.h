#ifndef MM
#define MM

void init_mm(void * heap_pointer,unsigned long long heap_size);
void * kmalloc(int size);
void free(void * p);

/* TODO later on, when we get more then one queue,  these should take some 
 * argument that specifies the queue.
 */
uint8_t dequeue();
void enqueue(uint8_t data);

#endif
