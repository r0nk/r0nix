#include <syscalls.h>
#include <kprint.h>
#include <cpu.h>
#include <panic.h>
#include <fs.h>

void system_call(struct Cpu_state *s)
{
	switch(s->eax){
		case SYSCALL_OPEN:
			s->eax = open((void *)s->ebx);
			return;
		case SYSCALL_READ:
			s->eax = read(s->ebx,(void *)s->ecx,s->edi);
			return;
		case SYSCALL_WRITE:
			s->eax = write(s->ebx,(void *)s->ecx,s->edi);
			return;
		case SYSCALL_CLOSE:
		case SYSCALL_FORK:
		case SYSCALL_EXEC:
			panic("nyi syscalled \n");
			break;
	}
}
