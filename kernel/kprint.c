#include <terminal.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <kprint.h>

static void f_string(char * s)
{
	int max = strlen(s);
	int i;
	for(i=0;i<max;i++)
		terminal_putchar(s[i]);
}

static void f_hex(unsigned int x)
{
	char s[9]="$$$$$$$$";
	itoha(x,s);
	f_string(s);
}

void kprintf(const char * format,...)
{
	va_list args;
	va_start(args,format);

	int i;
	int max = strlen(format);

	for(i=0;i<max;i++){
		if(format[i]=='%'){
			i++;
			switch(format[i]){
				case 'x':
					f_hex(va_arg(args,unsigned int));
					break;
				case 's':
					f_string(va_arg(args,char *));
					break;
				case '%':
					terminal_putchar('%');
					break;
				default:
					f_string("\n printf_Err, unrecognized option:");
					terminal_putchar(format[i]);
					f_string("\n");
					break;
			}
		}else{
			terminal_putchar(format[i]);
		}
	}
	va_end(args);
}
