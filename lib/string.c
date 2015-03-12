#include <stddef.h>

#include <kprint.h>
#include <mm.h>
#include <string.h>

size_t strlen(const char* str)
{
	size_t ret = 0;
	while (str[ret]!='\0')
		ret++;
	return ret;
}

char * strdup(char * str)
{
	int i;
	int len=strlen(str);
	char * ret = kmalloc(len);
	for(i=0;i<len;i++){
		ret[i]=str[i];
	}
	return ret;
}

int strcmp(const char *s1,const char *s2)
{
	int i;
	while(s1[i]==s2[i]){
		i++;
		if( (s1[i]=='\0') && (s2[i]=='\0') )
			return 0;/*then we've reached the end of the string*/
		else if ((s1[i]=='\0') || (s2[i]=='\0'))
			return -1;/*one stops before the other */
	}
	return 1;/*one of the characters is not equal*/
}
