#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "helloworld1";
	char s2[] = "helloworld2";
	if(strcmp(s1,s2)==1)
		puts("s1>s2");
	else if(strcmp(s1,s2)==-1)
		puts("s1<s2");
	else 
		puts("s1==s2");

	if(strncmp(s1,s2,strlen(s1)-1))
		puts("s1>s2");
	else if(strncmp(s1,s2,strlen(s1)-1)==-1)
		puts("s1<s2");
	else 
		puts("s1==s2");

	
	return 0;
}
