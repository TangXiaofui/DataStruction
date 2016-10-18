#include <stdio.h>

void binarySearch(int array[],int len,int k)
{
	int left = 0,right = len-1;
	int flag = 0;
	int mid;
	while(left <= right)
	{
		mid = (left + right)/2;
		if( k > array[mid] )
			left = mid+1;
		else if( k < array[mid] )
			right = mid -1;
		else 
		{
			flag = 1;
			break;
		}
	}
	
	if(flag)
		printf("mid = %d\n",array[mid]);
	else
		printf("not found\n");	



}

void gcd(int num1,int num2)
{

}

int main(int argc,char *argv[])
{
	int array[] = {1,3,4,8,11,19,28};
	int len = sizeof(array) / sizeof(array[0]);
	binarySearch(array,len,2);
	
	
	return 0;
}
