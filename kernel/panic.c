#include <kprint.h>
#include <panic.h>

/* TODO this should be moved else-where */
/* stops the cpu forever */
void panic_hlt()
{
//	asm("cli");/* disable all interrupts*/
	while(1)
		asm("hlt");/* sleep till we get a interrupt */
}

void panic(char * reason)
{
	kprintf("\n PANIC: %s \n",reason);
	panic_hlt();
}
