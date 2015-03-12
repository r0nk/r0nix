#ifndef MM
#define MM

void init_mm(void * heap_pointer,unsigned long long heap_size);
void * kmalloc(int size);
void free(void * p);

#endif
