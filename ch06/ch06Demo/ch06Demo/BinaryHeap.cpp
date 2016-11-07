#include "BinaryHeap.h"

BH InitialBH(BH bh,int size)
{
	if (bh == NULL)
	{
		bh = (BH)malloc(sizeof(struct BinaryHeap));
		bh->Capacity = size;
		bh->size = 0;

		bh->elems = (int *)malloc(sizeof(int)*size);
		bh->elems[0] = 0;
		return bh;
	}
}
void InsertBH(BH bh,int elem)
{
	if (bh != NULL)
	{
		//ʡ�����ж��Ƿ��Ѿ�����
		int i = 0;
		for (i = ++bh->size;bh->elems[i/2] > elem ; i /=2 )
		{
			bh->elems[i] = bh->elems[i/2];
		}
		bh->elems[i] = elem;
	}
}
void DeleteMin(BH bh)
{
	if (bh != NULL)
	{
		//ʡ����һЩ�Ϸ��Լ��

		int MinElem = bh->elems[1];
		int LastElem = bh->elems[bh->size--];
		int Child,i = 0;
		for (i = 1; i*2  <= bh->size ;  )
		{
			Child = 2*i;

			if (Child != bh->size && bh->elems[Child]>bh->elems[Child+1])
			{
				Child++;
			}

			if(LastElem > bh->elems[Child])
				bh->elems[i] = bh->elems[Child];
			else
				break;

			i = Child;
		}
		bh->elems[i] = LastElem;
	}
}

void PrintBH(BH bh)
{
	if (bh != NULL)
	{
		int i = 0 ;
		for (i = 1 ;i <= bh->size ;i++)
		{
			printf("%d ",bh->elems[i]);
		}
		printf("\n");
	}
}