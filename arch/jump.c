#include <jump.h>
#include <panic.h>

void jump(struct cpu_state state)
{
	/*
	 * We can't just popa and then iret, because popa moves our stack.
	 * So, we have to manually push the return pointer onto the new stack,
	 * then popa-iret.
	 */
	uint32_t * stack = (void *)state.esp;
	/*push the state onto the stack*/
	*(--stack) = state.eflags;
	*(--stack) = state.cs;
	*(--stack) = state.eip;
	*(--stack) = state.eax;
	*(--stack) = state.ecx;
	*(--stack) = state.edx;
	*(--stack) = state.ebx;
	*(--stack) = 0xdeadbeef;/*doesn't get pop-ped*/
	*(--stack) = state.ebp;
	*(--stack) = state.esi;
	*(--stack) = state.edi;

	asm("mov %%eax,%%esp;"::"a"(stack));
	asm("popa;");
	asm("iret;");
	panic("jump: reached after iret call,should never occur.");
}

