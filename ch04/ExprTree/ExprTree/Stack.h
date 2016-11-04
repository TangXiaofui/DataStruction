#ifndef  STACK_H
#define  STACK_H
#include "ExprTree.h"
#include <string.h>
#include <stdlib.h>

#define  MAXSIZE 20
#define EMPTY -1
struct Stack;
typedef struct Stack *stack;
typedef Node elem;


struct Stack
{
	int Capacity;
	int Top;
	elem **array;
};

void InitStack(stack *s,int size);
void Push(stack s,Node *n);
Node *Pop(stack s);

#endif