#ifndef BINARYHEAP
#define BINARYHEAP
#include <stdio.h>
#include <stdlib.h>

struct BinaryHeap
{
	int Capacity;
	int size;
	int *elems;
};

typedef struct BinaryHeap *BH;

BH InitialBH(BH bh,int size);
void InsertBH(BH bh,int elem);
void DeleteMin(BH bh);
void PrintBH(BH bh);


#endif