#include <stdio.h>
#include <ctype.h>


int main()
{
	char ach[10];
	int count=0, i;
	if(gets(ach)== NULL || ach[0]=='\0')
		return -1;
	for(i=0; i<strlen(ach); i++)
	{
		if(ispunct(ach[i]))
			count++;
		if(isupper(ach[i]))
			ach[i] = tolower(ach[i]);
		else
			ach[i] = toupper(ach[i]);	
	}

	puts(ach);
	printf("punctuation number is %d\n", count);
	return 0;
}
