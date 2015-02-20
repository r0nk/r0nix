#include "terminal.h"
#include "stdio.h"
#include "stdlib.h"

void kprint_string(char * s){
	terminal_writestring(s);
}

void kprint_int(unsigned int x){
	char s[9]="$$$$$$$$";
	itoha(x,s);
	kprint_string(s);
}

