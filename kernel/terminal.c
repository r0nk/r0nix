#include <stdint.h>
#include <stddef.h>
#include <terminal.h>
#include <string.h>
#include <drivers/vga.h>

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
