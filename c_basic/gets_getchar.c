#include <stdio.h>

int main()
{
	printf("gets get strings\n");
	char Name[100];
	while(gets(Name)!=NULL)
	{
		printf("gets Name: %s\n", Name);
		if(Name[0]=='\0')
			break;
	}

	printf("getchar get strings\n");
	char ch;
	while((ch=getchar())!=EOF)
	{
		printf("%c\n", ch);
		if(ch=='\n')
			break;
	}
	return 0;
}
