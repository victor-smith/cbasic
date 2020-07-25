#include <stdio.h>
#include <stdlib.h>
#include "list_.h"

void showmovies(Item item);

int main(void)
{
	List movies;
	Item temp;
	
	InitializeList(&movies);
	if(ListIsFull(movies))
	{
		fprintf(stderr, "No memory available ! Bye!\n");
		exit(1);
	}

	puts("Enter first movie title: ");
	while(gets(temp.title) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while(getchar() != '\n')
			continue;
		if(AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "No memory available ! Bye!\n");
			break;
		}
		
		if(ListIsFull(movies))
		{
			puts("This List is now full.");
			break;
		}
		
		puts("Enter next movie title (empty line to quit);");
	}

	if(ListIsEmpty(&movies))
		printf("No data entered\n");
	else
	{
		printf("Here are the movie list:");
		Traverse(&movies, showmovies);
	}
	
	printf("you entered %d movies\n", ListItemCount(&movies));
	
	EmptyTheList(&movies);
	printf("Bye!\n");
	return 0;
}

void showmovies(Item item)
{
	printf("Movie:%s Rating:%d\n", item.title, item.rating);
	return ;
}
