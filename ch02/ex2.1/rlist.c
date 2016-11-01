#include "rlist.h"
#include <stdio.h>
#include <stdlib.h>


rList rInit(rList *rl)
{
	*rl = (rList)malloc(sizeof(struct rNode));
	rHead = rTail = *rl;
	rHead->next =rHead;
	rHead->prev =rTail;	
}

prNode rInsert(rElemType elem,rList rl)
{
	prNode node = (prNode)malloc(sizeof(struct rNode));
	node->elem = elem;

	node->next = rl->next;
	node->prev = rl;
	rl->next->prev = node;
	rl->next = node;
}
prNode rDelete(rElemType elem,rList rl)
{
	while(rl->next->elem != elem && rl->next != rTail)
		rl = rl->next;
	
	if(rl->next != rTail)
	{
		prNode tmp = rl->next;
		rl->next = rl->next->next;
		rl->next->prev = rl;
	}

}

void rPrintList(rList rl,int direction)
{
	if(direction)
	{
		while(rl = rl->next)
		{
			if(rl == rTail)
			{
				break;
			}
			printf("%d ",rl->elem);
		}
		printf("\n");
	}
	else
	{
		while(rl = rl->prev)
		{
			if(rl == rTail)
				break;
			printf("%d ",rl->elem);
		}
		printf("\n");
	}
}


