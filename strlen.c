#include <stdio.h>
#include <string.h>

int main()
{

	char name[10]={};

	char s1[]="s1string";
	char s2[]={'1','2','3','4'};
	char s3[]="s3string";
	int n=0;

	strcat(name, "helloworld");
	printf("test string length is %d\n", strlen("test"));
	printf("%s len is %d \n", name, strlen(name));

	puts(s2);
	printf("%p\n%p\n%p\n%p\n%p\n", name, s1, s2, s3, &n);
	return 0;
}
