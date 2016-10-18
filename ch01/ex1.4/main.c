#include <stdio.h>

void binarySearch(int array[],int len,int k)
{
	int left = 0,right = len-1;
	int flag = 0;
	int mid;
	while(left <= right)
	{
		mid = (left + right)/2;
		if( k > mid )
			left = mid+1;
		else if( k < mid )
			right = mid;
		else 
		{
			flag = 1;
			break;
		}
	}
	
	if(flag)
		printf("mid = %d\n",mid);
	else
		printf("not found\n");	



}



int main(int argc,char *argv[])
{
	int array[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(array) / sizeof(array[0]);
	binarySearch(array,len,2);
	

	return 0;
}
