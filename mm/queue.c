#include <mm.h>
#include <pic.h>
#include <panic.h>
#include <kprint.h>

char q[1000];

char dequeue(){
	char ret;
	int i;

	if(q_size==0){
	 	/*halt the thread and do stuff*/
		panic("q_size=0");
	}

	ret=q[0];

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
