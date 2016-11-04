#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MINSIZE 10
#define EMPTY -1

typedef char  ElemType;
typedef struct stack{
	int Top;
	int capacity;
	ElemType *array;
}*Stack;

void InitStack(Stack *s,int size);

void Push(Stack s,ElemType elem);

ElemType Pop(Stack s);

ElemType Top(Stack s);

#endif