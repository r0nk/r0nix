#ifndef EXEC
#define EXEC
#include <cpu.h>

void jump(struct cpu_state state);
void exec(char * path);
void exec_inital(char * path);

#endif
