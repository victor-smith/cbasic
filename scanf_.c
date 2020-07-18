#include<stdio.h>

int main()
{
	char name1[10], name2[10];
	int num = scanf("%5s %5s", name1, name2);
	printf("%s, %s, %d\n", name1, name2, num);
	return 0;
}
