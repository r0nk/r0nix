/*TODO*/
#include <stdint.h>
#define IDT_SIZE 256

void setup_interrupts(){
	/* At some point, this should call the LIDT asm instruction*/
}

/* create an IDT, all of which call f */
void createIDT(void * at,void (*f)(void)){
	int i = 0;
	for(i=0;i<IDT_SIZE;i++){
		/*paste each of the elements into the table*/
	}
}
