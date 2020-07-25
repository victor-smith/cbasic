#include <stdio.h>


int mycompare(int * a1, int * a2);

int main()
{
	int arr[10]={1, 3, 5, 2, 7, 8, 4, 10, 9, 11},i;	
	qsort(arr, 10, sizeof(int), mycompare);

	for(i=0; i<10; i++)
	{
		printf("%d ",arr[i]);
	}	
	printf("\n");
	return 0;
}

int mycompare(int * a1, int * a2)
{
	if(*a1>*a2)
		return -1;
	else if(*a1<*a2)
		return 1;
	
	return 0;
}
