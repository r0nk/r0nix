#include <string.h>

/*
 * TODO:these should use some malloc function, but we don't have a malloc 
 * function yet, so we make due with the calling function passing us a string.
*/

void reverse(char *s)
{
	int i,j;
	char c;

	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char *s)
{
	int i, sign;

	if((sign=n)<0)
		n=-n;
	i=0;
	do{
		s[i++] = n % 10 + '0';
	} while ((n /=10) > 0);
	if(sign<0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/*
 * Converts a integer to a hex representation in ascii
 */
void itoha(unsigned int in,char * s)
{
	int len=strlen(s)-1;
	int shifter=0;
	int mask=0xf;
	int a;
	while(len>=0){
		a=(in&mask)>>shifter;
		if(a>=0 && a<10){
			s[len]=(char)(a+0x30);
		}else if(a>9){
			s[len]=(char)(a+55);
		}
		shifter+=4;
		mask*=0x10;
		len--;
	}
}
