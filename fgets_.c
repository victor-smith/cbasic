#include <stdio.h>

int main()
{
	char *name = (char*)malloc(sizeof(char)*100);
	char *ptr;
	ptr = fgets(name, 100, stdin);
	printf("%s:%s;%p:%p\n", name, ptr, name, ptr);
	return 0;
}
