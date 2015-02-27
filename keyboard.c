#include "keyboard.h"
#include "stdio.h"
#include "io.h"
#include "terminal.h"

#define KEY_RELEASED(s) (s&0x80)
#define SHIFT_CODE(x) (x == KRLEFT_SHIFT || x == KRRIGHT_SHIFT)

static int shift_down;

/*TODO we should change the way this is handled */
/* Non-Shifted scancodes to ASCII: */
static char asciiNonShift[] = {
0 , ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', BACKSPACE,
TAB, 'q', 'w',   'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',   '[', ']', ENTER, 0,
'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, 0, 0, ' ', 0,
KF1, KF2, KF3, KF4, KF5, KF6, KF7, KF8, KF9, KF10, 0, 0,
KHOME, KUP, KPGUP,'-', KLEFT, '5', KRIGHT, '+', KEND, KDOWN, KPGDN, KINS, KDEL, 0, 0, 0, KF11, KF12 };

/* Shifted scancodes to ASCII: */
static char asciiShift[] = {
0, ESC, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', BACKSPACE,
TAB, 'Q', 'W',   'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',   '{', '}', ENTER, 0,
'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~', 0, '|',
'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, 0, 0, ' ', 0,
KF1,   KF2, KF3, KF4, KF5, KF6, KF7, KF8, KF9, KF10, 0, 0,
KHOME, KUP, KPGUP, '-', KLEFT, '5',   KRIGHT, '+', KEND, KDOWN, KPGDN, KINS, KDEL, 0, 0, 0, KF11, KF12 };

static char scancode_to_ascii(int scancode){
	if(shift_down)
		return asciiShift[scancode];
	else
		return asciiNonShift[scancode];
}

void enable_keyboard(){
	outb(0x21,0xfd);
	outb(0xa1,0xff);
	asm("sti");
}

void keyboard_irq()
{
	char scancode;
	char str[2];
	str[0]='\0';str[1]='\0';
	scancode = inb(0x60);
	kprint_string("key scancode:");
	kprint_int(scancode);
	kprint_string("\n");
	if(KEY_RELEASED(scancode)){
		if(SHIFT_CODE(scancode))
			shift_down=0;
		return;
	}else{
		if(SHIFT_CODE(scancode)){
			shift_down=1;
		}else{
			str[0]=scancode_to_ascii(scancode);
			kprint_string(str);
		}
	}
}
