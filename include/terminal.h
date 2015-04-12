#include <stdint.h>
#include <stddef.h>
#ifndef TERMINAL
#define TERMINAL 1

struct Terminal{
	size_t row;
	size_t column;
	uint8_t color;
	uint16_t* buffer;
};

/* This probably shouldn't be a global, but It's going to be a while till we 
 * have more then one terminal.
 */
struct Terminal term;

void initialize_terminal();
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_writestring(const char* data);

#endif
