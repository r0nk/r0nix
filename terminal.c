#include <stdint.h>
#include <stddef.h>
#include "terminal.h"
#include "string.h"

enum vga_color
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

uint8_t make_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

uint16_t make_vgaentry(char c, uint8_t color)
{
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

void terminal_initialize()
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	size_t y,x;
	for ( y = 0; y < VGA_HEIGHT; y++ ){
		for ( x = 0; x < VGA_WIDTH; x++ ){
			const size_t i = y * VGA_WIDTH + x;
			terminal_buffer[i] = make_vgaentry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}

inline void terminal_shift_up(){
	int x,y;
	int n,i=1;
	for ( y = 0; y < (VGA_HEIGHT); y++ ){
		for ( x = 0; x < VGA_WIDTH; x++ ){
			i = y * VGA_WIDTH + x;
			n = (y+1) * VGA_WIDTH + x;
			if(!terminal_buffer[i])
				break;
			terminal_buffer[i] = terminal_buffer[n];
		}
		if(!terminal_buffer[i])
			break;
	}
	terminal_row--;
}

/* Fix terminal location, scroll terminal, etc. */
static void terminal_normalize()
{
	if (terminal_column >= VGA_WIDTH){
		terminal_column = 0;
		terminal_row++;
	}
	if (terminal_row >= VGA_HEIGHT){
		terminal_shift_up();
	}
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c)
{
	if(c=='\n'){
		terminal_column=0;
		terminal_row++;
	}else{
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		terminal_column++;
	}
	terminal_normalize();
}

void terminal_writestring(const char* data)
{
	size_t datalen = strlen(data);
	size_t i;
	for ( i = 0; i < datalen; i++ )
		terminal_putchar(data[i]);
}
