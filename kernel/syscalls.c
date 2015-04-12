#include <syscalls.h>
#include <desc.h>
#include <kprint.h>
#include <cpu.h>
#include <panic.h>
#include <fs.h>
#include <fork.h>
#include <scheduler.h>

void system_call(struct cpu_state *s)
{
	switch(s->eax){
		case SYSCALL_OPEN:
			s->eax = open((void *)s->ebx);
			break;
		case SYSCALL_CLOSE:
			s->eax = close(s->ebx);
			break;
		case SYSCALL_READ:
			s->eax = read(s->ebx,(void *)s->ecx,s->edi);
			break;
		case SYSCALL_WRITE:
			s->eax = write(s->ebx,(void *)s->ecx,s->edi);
			break;
		case SYSCALL_FORK:
			s->eax = fork();
			break;
		case SYSCALL_EXEC:
			panic("nyi exec system called");
			break;
		case SYSCALL_REBOOT:
			/*hack, causes a triple fault, which causes reboot*/
			load_idt(0);
			asm("int3");
			break;
		case SYSCALL_EXIT:
			panic("SYSCALL_EXIT NYI");
			break;
		case SYSCALL_FSTAT:
			panic("SYSCALL_FSTAT NYI");
			break;
		case SYSCALL_GETPID:
			panic("SYSCALL_GETPID NYI");
			break;
		case SYSCALL_ISATTY:
			panic("SYSCALL_ISATTY NYI");
			break;
		case SYSCALL_KILL:
			panic("SYSCALL_KILL NYI");
			break;
		case SYSCALL_LINK:
			panic("SYSCALL_LINK NYI");
			break;
		case SYSCALL_LSEEK:
			panic("SYSCALL_LSEEK NYI");
			break;
		case SYSCALL_SBRK:
			panic("SYSCALL_SBRK NYI");
			break;
		case SYSCALL_STAT:
			panic("SYSCALL_STAT NYI");
			break;
		case SYSCALL_TIMES:
			panic("SYSCALL_TIMES NYI");
			break;
		case SYSCALL_UNLINK:
			panic("SYSCALL_UNLINK NYI");
			break;
		case SYSCALL_WAIT:
			panic("SYSCALL_WAIT NYI");
			break;
		default:
			kprintf("\ns->eax:%i\n",s->eax);
			panic("Unknown system call called.");
			break;
	}
}
