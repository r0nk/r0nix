#ifndef SYSCALLS
#define SYSCALLS
#include <cpu.h>

#define SYSCALL_OPEN  0 
#define SYSCALL_CLOSE 1 
#define SYSCALL_READ  2
#define SYSCALL_WRITE 3 
#define SYSCALL_FORK  4 
#define SYSCALL_EXEC  5 
#define SYSCALL_REBOOT 0x99

void system_call(struct cpu_state * s);

#endif
