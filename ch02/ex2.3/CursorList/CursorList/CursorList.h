#ifndef CURSORLIST_H
#define CURSORLIST_H
#include <stdio.h>
#define MAXLIST 10

struct PtrNode;
typedef int ElemType;
typedef struct PtrNode pNode;
typedef int Pos;

struct PtrNode{
	ElemType elem;
	Pos next;
};

pNode list[MAXLIST];

Pos CursorAlloc(void)
{
	Pos p;
	p = list[0].next;
	list[0].next = list[p].next;
	return p;
}

void CursorFree(Pos p)
{
	list[p].next = list[0].next;
	list[0].next = p;
}

void InitCursorList(void)
{
	int i = 0;
	for (i = 0; i < MAXLIST ;i++)
	{
		list[i].elem = 0;
		if (i == MAXLIST-1)
			list[i].next = 0;
		else
			list[i].next = i+1;
	}
}
void InsertElem(Pos p,ElemType elem)
{
	Pos temp = CursorAlloc();
	list[temp].elem = elem;
	list[temp].next = list[p].next;
	list[p].next = temp;
}
void DeleteElem(Pos p,ElemType elem)
{
	Pos temp;
	while(list[p].next != 0)
	{
		if (list[ list[p].next ].elem == elem)
		{
			break;
		}
		p = list[p].next;
	}
	if ( list[p].next != 0 )
	{
		temp = list[p].next;
		list[p].next = list[temp].next;
		CursorFree(temp);
	}
}
void PrintElem(Pos p)
{
	while (list[p].next != 0)
	{
		printf("%d ",list[list[p].next].elem);
		p = list[p].next;
	}
	printf("\n");
}


#endif