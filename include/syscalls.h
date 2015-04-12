#ifndef SYSCALLS
#define SYSCALLS
#include <cpu.h>

#define SYSCALL_OPEN	0 
#define SYSCALL_CLOSE	1 
#define SYSCALL_READ	2
#define SYSCALL_WRITE	3 
#define SYSCALL_FORK	4 
#define SYSCALL_EXEC	5 
#define SYSCALL_EXIT	6 
#define SYSCALL_FSTAT	7 
#define SYSCALL_GETPID	8 
#define SYSCALL_ISATTY	10 
#define SYSCALL_KILL	11 
#define SYSCALL_LINK	12 
#define SYSCALL_LSEEK	13 
#define SYSCALL_SBRK	14 
#define SYSCALL_STAT	15 
#define SYSCALL_TIMES	16 
#define SYSCALL_UNLINK	17 
#define SYSCALL_WAIT	18 
#define SYSCALL_REBOOT	0x99

void system_call(struct cpu_state * s);

#endif
