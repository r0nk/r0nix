#include <panic.h>
#include <scheduler.h>
#include <fork.h>

int fork(){
	/*TODO*/
	int pid = 0x70d0;
	/*clone this process*/
	/*add clone to scheduler*/
	/*set clone return to 0*/
	/*return pid*/
	panic("fork not yet implemented.");
	return pid;
}
