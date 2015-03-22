/* Wasn't really sure where to put this guy, so I just threw him in arch.
 * He maybe should be moved somwhere else.
 */

#include <stdint.h>
#include <stddef.h>
#include <terminal.h>
#include <string.h>

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

inline uint8_t make_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

uint16_t make_vgaentry(char c, uint8_t color)
{
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

void initialize_terminal()
{
	term.row = 0;
	term.column = 0;
	term.color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	term.buffer = (uint16_t*) 0xB8000;
	size_t y,x;
	for ( y = 0; y < VGA_HEIGHT; y++ ){
		for ( x = 0; x < VGA_WIDTH; x++ ){
			const size_t i = y * VGA_WIDTH + x;
			term.buffer[i] = make_vgaentry(' ', term.color);
		}
	}
}

inline void terminal_shift_up()
{
	int x,y;
	int n,i=1;
	for ( y = 0; y < (VGA_HEIGHT); y++ ){
		for ( x = 0; x < VGA_WIDTH; x++ ){
			i = y * VGA_WIDTH + x;
			n = (y+1) * VGA_WIDTH + x;
			if(!term.buffer[i])
				break;
			term.buffer[i] = term.buffer[n];
		}
		if(!term.buffer[i])
			break;
	}
	term.row--;
}

/* Fix terminal cursor location, scroll terminal, etc. */
static void terminal_normalize()
{
	if (term.column >= VGA_WIDTH){
		term.column = 0;
		term.row++;
	}
	if (term.row >= VGA_HEIGHT)
		terminal_shift_up();
}

inline void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	term.buffer[(y * VGA_WIDTH + x)] = make_vgaentry(c, color);
}

void terminal_putchar(char c)
{
	if(c=='\n'){
		term.column=0;
		term.row++;
	}else if (c=='\r'){
		term.column=0;
	}else{
		terminal_putentryat(c, term.color, term.column, term.row);
		term.column++;
	}
	terminal_normalize();
}
