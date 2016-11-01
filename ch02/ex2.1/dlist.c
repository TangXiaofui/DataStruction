#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>
dList dInit(dList l)
{
	l = (pdNode)malloc(sizeof(struct dNode));
	if(l != NULL)
	{
		l->next = NULL;
		l->prev = NULL;
		dHead = dTail = l;
		return l;
	}
}
pdNode dInsert(dElemType elem,dList l)
{
	if(l != NULL)
	{
		pdNode node = (pdNode)malloc(sizeof(struct dNode));
		node->elem = elem;
		node->next = l->next;
		node->prev = l;
		if(l->next)
			l->next->prev = node;
		else
			dTail = node;
		l->next = node;	
	}
}

pdNode dDelete(dElemType elem,dList l)
{	
	if(l != NULL)
	{
		while(l->next)
		{
			if(l->next->elem == elem)
			{
				break;
			}
			l = l->next;
		}
		if(l->next != NULL)
		{
			pdNode tmp = l->next;
			l->next = l->next->next;
			if(l->next != NULL)
			 	l->next->prev = l;
			free(tmp);
			tmp = NULL;
		}
	}
}
void dPrintList(dList l,int direction)
{
	if(l != NULL)
	{
		if(direction)
		{
			while(l = l->next)
			{
					printf("%d ",l->elem);
			}
		}
		else
		{
			while(l->prev)
			{
				if(l == dHead)
					break;
				printf("%d ",l->elem);
				l = l->prev;
			}
		}
		printf("\n");
	}
}
