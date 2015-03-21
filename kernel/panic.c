#include <kprint.h>
#include <panic.h>

void panic_hlt()
{
	asm("cli");/* disable interrupts*/
	while(1)
		asm("hlt");/* wait for an interrupt. */
}

void panic(char * reason)
{
	kprintf("\n PANIC: %s \n",reason);
	panic_hlt();
}
