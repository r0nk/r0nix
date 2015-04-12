#include <stdint.h>
#include <stddef.h>
#ifndef TERMINAL
#define TERMINAL 1

enum vga_color;

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

struct Terminal{
	size_t row;
	size_t column;
	uint8_t color;
	uint16_t* buffer;
};


/* This probably shouldn't be a global, but Its going to be a while till we 
 * have more then one terminal.
 */
struct Terminal term;

uint8_t make_color(enum vga_color fg, enum vga_color bg);
uint16_t make_vgaentry(char c, uint8_t color);
void initialize_terminal();
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_writestring(const char* data);

#endif
