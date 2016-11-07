#include <stdio.h>
#include "BinaryHeap.h"

int main(int argc,char *argv[])
{
	BH temp = NULL;
	temp = InitialBH(temp,11);
	InsertBH(temp,3);
	InsertBH(temp,1);
	InsertBH(temp,4);
	InsertBH(temp,2);
	DeleteMin(temp);

	PrintBH(temp);
	return 0;
}