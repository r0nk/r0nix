#include <syscalls.h>
#include <kprint.h>
#include <cpu.h>

void system_call(struct Cpu_state s)
{
	switch(s.eax){
		case SYSCALL_OPEN:
		case SYSCALL_CLOSE:
		case SYSCALL_READ:
		case SYSCALL_WRITE:
		case SYSCALL_FORK:
		case SYSCALL_EXEC:
			kprintf("SYSTEM CALL:%x\n",s.eax);
	}
}
