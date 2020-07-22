#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char pstr1[] = "hello world", pstr2[]="nihao", pstr3[]="pstr3";

	memcpy(pstr1, pstr2, strlen(pstr2));
	memmove(pstr2, pstr3, strlen(pstr2));

	puts(pstr1);
	puts(pstr2);	
	
	//memcpy(pstr1, pstr1+3, strlen(pstr1)-3);
	memmove(pstr1, pstr1+3, strlen(pstr1)-3);
	puts(pstr1);
	return 0;
}
