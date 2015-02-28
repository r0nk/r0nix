#include "include/string.h"

/*
 * TODO:these should use some malloc function, but we don't have a malloc 
 * function yet, so we make due with the calling function passing us a string.
*/

/*
 * Converts a integer to a hex representation in ascii
 */
void itoha(unsigned int in,char * s)
{
	int len=strlen(s)-1;
	int shifta=0;
	int train=0xf;
	int from;
	while(len>=0){
		from=(in&train)>>shifta;
		if(from>=0 && from<10){
			s[len]=(char)(from+0x30);
		}else if(from>9){
			s[len]=(char)(from+55);
		}
		shifta+=4;
		train*=0x10;
		len--;
	}
}
