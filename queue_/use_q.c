#include <stdio.h>
#include "queue_.h"

int main()
{
	Queue line;
	Item temp;
	char ch;
	int item;

	InitializeQueue(&line);
	puts("Test Queue, input a to add one item");
	puts("input d to delete one item, q to quit");
	while((ch = getchar())!='q')
	{
		if(!(ch == 'a' || ch == 'd'))
		{
			fprintf(stderr, "input error.\n");
			continue;
		}

		switch(ch)
		{
			case 'a':
				puts("input one integer item:");
				scanf("%d", &item);
				EnQueue(item, &line);
			break;
			case 'd':
				if(DeQueue(&item, &line))
					printf("dequeue the item is %d\n", item);
			break;
		}
		while((ch=getchar())!='\n') continue;
		puts("Test Queue, input a to add one item");
		puts("input d to delete one item, q to quit");
	}
	
	EmptyQueue(&line);
	puts("Bye");
	return 0;
}
