#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist)
{
	*plist = NULL;
}


bool ListIsEmpty(const List *plist)
{
	if(*plist == NULL)
		return true;
	return false;
}


bool ListIsFull(const List *plist)
{
	Node *pt;

	pt = (Node*) malloc(sizeof(Node));
	if(pt == NULL)
		return true;

	return false;
}

unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = *plist;
	
	while(pnode != NULL)
	{
		count ++;
		pnode = pnode->next;
	}

	return count;
}

bool AddItem(Item item, List *plist)
{
	Node *ptr = *plist;
	Node *pnode= (Node*)malloc(sizeof(Node));

	if(pnode== NULL)
	{
		fprintf(stderr, "malloc failed\n");
		return false;
	}	
	
	CopyToNode(item, pnode);
	pnode->next = NULL;
	
	if(ListIsEmpty(plist))
	{
		*plist = pnode;
	}
	else
	{
		while(ptr->next !=NULL)
		{
			ptr = ptr->next;
		}	
		ptr->next = pnode;
	}
	
	return true;
}


void Traverse(const List *plist, void (*func)(Item item))
{
	Node *pnode = *plist;
	while(pnode != NULL)
	{
		(*func)(pnode->item);
		pnode = pnode->next;
	}
}


void EmptyTheList(List *plist)
{
	Node *pnode = *plist;
	while(pnode != NULL)
	{
		free(pnode);
		pnode = pnode->next;
	}
	*plist = NULL;
}


static void CopyToNode(Item item, Node *pnode)
{
	strncpy(pnode->item.title, item.title, strlen(item.title));
	pnode->item.rating = item.rating;
}
