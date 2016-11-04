#include "Stack.h"

void InitStack(stack *s,int size)
{
	size = size > MAXSIZE ? size : MAXSIZE;

	*s = (stack)malloc(sizeof(struct Stack));
	(*s)->Capacity = size;
	(*s)->Top = EMPTY;
	(*s)->array = (elem **)malloc(sizeof(elem*) * size);
}

void Push(stack s,elem *n)
{
	if (s == NULL || s->Top >= s->Capacity)
	{
		return;
	}
	s->array[s->Top++] = n;

}
Node *Pop(stack s)
{
	if (s == NULL || s->Top < 0)
	{
		return NULL;
	}
	
	return s->array[--s->Top];
}