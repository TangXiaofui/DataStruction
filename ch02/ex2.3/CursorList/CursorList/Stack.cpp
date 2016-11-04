#include "stdafx.h"
#include "Stack.h"

void InitStack(Stack *s,int size)
{
	size = size > MINSIZE ? size :MINSIZE;

	*s = (Stack)malloc(sizeof(struct stack));
	if (*s == NULL)
	{
		printf("Malloc fail \n");
		return ;
	}
	(*s)->Top = EMPTY;
	(*s)->array = (ElemType *)malloc(sizeof(ElemType) * size);

	if ((*s)->array == NULL)
	{
		printf("Malloc fail \n");
		return ;
	}
	(*s)->capacity = size;
}

void Push(Stack s,ElemType elem)
{
	if(s == NULL)
	{
		return ;
	}
	s->Top++;
	if (s->Top >= s->capacity)
	{
		return ;
	}
	s->array[s->Top] = elem;

}

ElemType Pop(Stack s)
{
	if (s == NULL)
	{
		return -1;
	}
	if (s->Top >= 0)
		return s->array[s->Top--];
	return -1;
}

ElemType Top(Stack s)
{
	if (s == NULL)
	{
		return -1;
	}
	if (s->Top == -1)
	{
		return -1;
	}
	if (s->Top >= 0)
	{
		return s->array[s->Top];
	}
}