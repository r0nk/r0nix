#include <syscalls.h>
#include <kprint.h>
#include <cpu.h>
#include <panic.h>
#include <fs.h>

void system_call(struct Cpu_state *s)
{
	kprintf("We got a syscall on aile %x\n",s->eax);
	switch(s->eax){
		case SYSCALL_OPEN:
			s->eax = open((void *)s->ebx);
			break;
		case SYSCALL_READ:
			s->eax = read(s->ebx,(void *)s->ecx,s->edi);
			break;
		case SYSCALL_WRITE:
			kprintf("ebx:%x ecx:%x edi:%x\n",s->ebx,s->ecx,s->edi);
			s->eax = write(s->ebx,(void *)s->ecx,s->edi);
			break;
		case SYSCALL_CLOSE:
		case SYSCALL_FORK:
		case SYSCALL_EXEC:
			panic("nyi syscalled");
			break;
	}
	panic("Syscalled");
}
