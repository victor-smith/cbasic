#include <stdio.h>
#include <stdlib.h>
#include "queue_.h"
#include <stdbool.h>

static void CopyToNode(Item item, Node *pnode);
static void CopyToItem(Node *pn, Item *Pi);

void InitializeQueue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
	return pq->items == 0;
}

int QueueItemCount(const Queue *pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue *pq)
{
	if(QueueIsFull(pq))
	{
		fprintf(stderr,"Queue is full.\n");
		return false;
	}

	Node *pnode = (Node*)malloc(sizeof(Node));
	pnode->next = NULL;
	CopyToNode(item, pnode);
	
	if(QueueIsEmpty(pq))
	{
		pq->front = pnode;
	}
	else
	{
		pq->rear->next = pnode;
	}

	pq->rear = pnode;
	pq->items ++;
	
	return true;
}

bool DeQueue(Item *pi, Queue *pq)
{
	if(QueueIsEmpty(pq))
	{
		fprintf(stderr, "Queue is empty.\n");
		return false;
	}
	
	Node *pn = pq->front;
	CopyToItem(pn, pi);
	pq->front = pq->front->next;
	pq->items --;
	
	if(pq->items == 0)
		pq->rear = NULL;
	free(pn);

	return true;
}

void EmptyQueue(Queue *pq)
{
	Item dummy;
	while(!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}


static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}

static void CopyToItem(Node *pn, Item *pi)
{
	*pi = pn->item;
}
