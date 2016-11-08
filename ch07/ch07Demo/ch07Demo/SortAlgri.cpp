#include "SortAlgri.h"


void InsertSort(int a[],int len)
{
	int i = 0;
	int p ;
	for (i = 1;i < len; i++)
	{
		int tmp = a[i];
		for(p = i; p > 0 && a[p-1] > tmp ;p--)
		{
			a[p] = a[p-1];
		}
		a[p] = tmp;
	}
}


void ShellSort(int a[],int len)
{
	int increase,i,j;
	int temp;
	for (increase = len / 2; increase > 0; increase /= 2)
	{
		for (i = increase ; i < len ; i++)
		{
			temp = a[i];
			for (j = i ; j >= increase ; j -= increase)
			{
				if (a[j-increase] > temp)
				{
					a[j] = a[j - increase];
				}
				else
					break;
			}
			a[j] = temp;
		}
	}
}
void  Swap(int *x1, int *x2)
{
	*x2 = *x1 + *x2;
	*x1 = *x2 - *x1;
	*x2 = *x2 - *x1;
}

#define LeftChild(i) (2*(i)+1)

void BuildHeap(int a[],int i , int len)
{
	int Child;
	int temp;
	for (temp = a[i] ; LeftChild(i) < len ; i = Child)
	{
		Child = LeftChild(i);
		if (Child != len-1 && a[Child] < a[Child + 1])
		{
			Child++;
		}
		if (temp > a[Child])
		{
			break;
		}
		else
			a[i] = a[Child];
	}
	a[i] = temp;
}


void HeapSort(int a[],int len)
{
	for (int i = len / 2 ; i >= 0; i-- )
	{
		BuildHeap(a,i,len);
	}
	for (int i = len - 1 ; i > 0 ;i--)
	{
		Swap(&a[0],&a[i]);
		BuildHeap(a,0,i);
	}
}



void PrintArray(int a[],int len)
{
	int i = 0;
	for (i = 0 ;i < len ;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}