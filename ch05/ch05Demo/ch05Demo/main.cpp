#include <stdio.h>
#include "HashTable.h"

int main(int argc,char*argv[])
{
	hTable ht = NULL;
	ht = InitialHashTable(ht,12);
	InsertHash(ht,1);
	InsertHash(ht,2);
	InsertHash(ht,3);
	printf("%d\n",FindHashNode(ht,3)->elem);

	InitialHashTable(ht,12);
	InsertHash(ht,3);
	if (FindHashNode(ht,3))
	{
		printf("success \n");
	}
	else
	{
		printf("fail \n");
	}


	return 0;
}