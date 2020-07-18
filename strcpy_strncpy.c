#include <stdio.h>
#include <string.h>
#define LEN 50

int main()
{
	char pstr1[LEN] = "hello world! you can be the best one";
	char pstr2[LEN] = "yes, you can be someone";

	char ptmp[LEN] = "123456789abcdefghijklmno";

	puts(pstr1);
	puts(pstr2);
	printf("ptmp len is %d\n", strlen(ptmp));

	strncpy(ptmp, pstr1, strlen(pstr1));
	ptmp[strlen(pstr1)]='\0';
/*
puts("step1");
puts(ptmp);
puts(pstr1);
puts("step1 end");
*/

	strncpy(pstr1,pstr2, strlen(pstr2));
	pstr1[strlen(pstr2)]='\0';
/*
puts("step2");
puts(pstr1);
puts(pstr2);
puts("step2 end");
*/
	strncpy(pstr2,ptmp, strlen(ptmp));
	pstr2[strlen(ptmp)]='\0';
/*
puts("step3");
puts(pstr2);
puts(ptmp);
puts("step3 end");
*/
	
puts(pstr1);
puts(pstr2);
	return 0;	
}
