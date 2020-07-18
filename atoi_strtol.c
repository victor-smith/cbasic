#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	char number[20];
	char *ptr;
	
	while(gets(number) != NULL && number[0] != '\0')
	{
		puts("get the number is:");
	
		printf("%s to number is %d\n", number,atoi(number));
		printf("%s to number is %d, ptr val is %s(%c)\n", number,strtol(number, &ptr,16), ptr, *ptr);
	}
	return 0;
}
