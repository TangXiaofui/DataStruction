#include <stdio.h>
#include "SortAlgri.h"

int main(int argc,char *argv[])
{
	int a[] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int len = sizeof(a)/sizeof(a[0]);
	//InsertSort(a,len);
	//ShellSort(a,len);
	HeapSort(a,len);

	PrintArray(a,len);

	int t[2] = {1,1};
	Swap(&t[0],&t[1]);
	PrintArray(t,2);
	return 0;
}