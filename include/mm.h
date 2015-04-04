#ifndef MM
#define MM

void init_mm();
void * kmalloc(int size);
void free(void * p);

/* TODO these shouldn't really be globals */
char * q;
int q_size;
/* TODO These should take some argument that specifies the queue. */
char dequeue();
void enqueue(char data);

#endif
