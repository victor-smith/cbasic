#include <stdio.h>

int main()
{
	char *name = (char*)malloc(sizeof(char)*100);
	char *ptr;
	ptr = fgets(name, 100, stdin);
	// after learn the strchr, then change the code
	char *pend = strchr(name, '\n');
	if(pend)
		*pend = '\0';
	//end
	printf("%s:%s;%p:%p\n", name, ptr, name, ptr);
	return 0;
}
