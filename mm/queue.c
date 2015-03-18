#include <mm.h>
#include <panic.h>
#include <kprint.h>

char dequeue(){
	char ret = q[0];
	int i;
	if(q_size==0)//wait till we get some input
		asm("hlt");

	for(i=0;i<q_size;i++)
		q[i]=q[i+1];
	q_size--;
	return ret;
}

void enqueue(char c){
	int i;
	if(q_size>1000)
		panic("q ran out of space");
	q_size++;
	for(i=q_size;i>0;i--)
		q[i]=q[i-1];
	q[0]=c;
}
