#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
List Init(List l)
{
	l = (pNode)malloc(sizeof(struct Node));
	assert(l != NULL);
	l->next = NULL;
	Head = l;
	return Head;
}

pNode Insert(ElemType elem,List l)
{
	assert( l != NULL );	
	pNode node = (pNode)malloc(sizeof(struct Node));
	
	assert( node != NULL );
	
	node->elem = elem;
	node->next = l->next;
	l->next = node;
	
	return node; 
}

pNode Delete(ElemType elem,List l)
{
	assert(l != NULL);
	while(l->next)
	{
		if(l->next->elem == elem)
		{
			break;
		}
		l = l->next;
	}	
	if(l->next)
	{	pNode node = l->next;
		l->next = node->next;
		free(node);
		node = NULL;
	}
	return l;
}

pNode Find(ElemType elem,List l)
{
	assert(l != NULL);
	
	while(l = l->next)
	{
		if(l->elem == elem)
		{
			break;
		}
	}
	return l;
}

void PrintList(List l)
{
	if(l)
	{
		while(l = l->next)
		{
			printf("%d ",l->elem);
		}
	}
	printf("\n");
}
