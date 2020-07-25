#include <stdio.h>

#define PR(X,...) printf("Message " #X ": " __VA_ARGS__)

int main()
{
	PR(1, " %s ...\n","hello world");
	return 0;
}
