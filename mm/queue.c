#include <mm.h>
#include <pic.h>
#include <panic.h>
#include <kprint.h>

char dequeue(){
	char ret = q[0];
	int i;

	if(q_size==0){
		asm("sti");
		acknowledge_interrupt(0x80);
		while(q_size==0) 
			asm("hlt");//wait till we get some input
	}

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
