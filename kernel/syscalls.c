#include <syscalls.h>
#include <kprint.h>
#include <cpu.h>
#include <panic.h>
#include <fs.h>

void system_call(struct Cpu_state *s)
{
	switch(s->eax){
		case SYSCALL_OPEN:
			s->eax = open(s->ebx);
			return;
		case SYSCALL_READ:
			s->eax = read(s->ebx,s->ecx,s->edi);
			return
		case SYSCALL_CLOSE:
		case SYSCALL_WRITE:
		case SYSCALL_FORK:
		case SYSCALL_EXEC:
			panic("nyi syscalled %x\n",s->eax);
			break;

	}
}
