#include <stdio.h>

void exit_call()
{
	puts("call exit_call");
}


int main()
{
	atexit(exit_call);
	puts("before main exit");
	return 0;
}
