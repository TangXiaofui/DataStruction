#include <stdio.h>
#include <string.h>
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void print(int a[],int n)
{
	int i = 0;
	for(i = 0 ; i < n ; i++)
		printf("%d ",a[i]);
	printf("\n");
}

void BulbSort(int a[],int n)
{
	int i = 0, j = 0;
	int flag = 0;

	for(i = n;i > 0 && !flag  ; i--)
	{
		for(j = 1; j < i ; j++)
		{
			if(a[j-1] > a[j])
			{
				swap(&a[j-1],&a[j]);
				flag = 0;
			}
		}
	}
}

int reverse(int a[],int l,int r)
{
	if(l >= r)
		return 0;
	swap(&a[l],&a[r]);
	reverse(a,l+1,r-1);
}

int recursion(int a[],int n)
{
	int l = 0;
	int r = n;
next:
	if(l >= r)
		return 0;
	swap(&a[l++],&a[r--]);
	goto next;
}

int RecursionSum(int a[],int l,int r)
{
	if(l >= r)
		return a[r];
	int mid = (l+r) >> 1;
	return RecursionSum(a,l,mid) + RecursionSum(a,mid+1,r);
}

int Max2(int a[],int n,int *x1,int *x2)
{
	if(a[*x1 = 0] < a[*x2 = 1])
		swap(x1,x2);
	int i = 0;
	for(i = 2; i < n ;i++)
	{
		if(a[*x2] < a[i])
			if(a[*x1] < a[*x2 = i])
				swap(x1,x2);
	}	
}

int fibonaci(int n)
{
	int x1 = 1,x2 = 1;
	int i = 0;
	while(i++ < n)
	{
		x2 = x2 + x1;
		x1 = x2 - x1;
	}
	return x1;
}
//has some problem
int FindSubstr(char *data1,int n1,char *data2,int n2)
{
	int a[50][50];
	memset(a,0,sizeof(a));
	int i = 0,j = 0;
	int flag = 0;
	for(i = 0; i < n2+1 ;i++)
	{
		flag = 0;
		for(j = 0; j < n1+1 ; j++)
		{
			if(data2[i] == data1[j])
				a[i+1][j+1] = a[i][j]+1;
			else	
				a[i+1][j+1] = a[i][j+1] > a[i+1][j] ? a[i][j+1] : a[i+1][j];
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	int temp = -1;
	for(i = 1 ; i < n1+1 ; i++)
	{
		if(temp != a[n2][i])
		{
			temp = a[n2][i];
			printf("%c",data1[i-1]);
		}
	}
	printf("\n");
}

int main(int argc,char *argv[])
{
	int array[] = {6,5,7,4,3,2,111};
	int n = sizeof(array)/sizeof(array[0]);
	print(array,n);
	
	BulbSort(array,n);
	print(array,n);

	reverse(array,0,n-1);
	print(array,n);
	
	recursion(array,n-1);
	print(array,n);
	
	printf("sum = %d\n",RecursionSum(array,0,n-1));

	int x1,x2;
	Max2(array,n,&x1,&x2);
	printf("max1 = %d,max2 = %d\n",array[x1],array[x2]);

	int i = 0;
	for(i = 0; i < 10 ;i++)
	{
		printf("%d ",fibonaci(i));
	}
	printf("\n");

	char *data1 = "didactical";
	char *data2 = "advantage";
	int n1 = strlen(data1);
	int n2 = strlen(data2);
	FindSubstr(data1,n1,data2,n2);
	return 0;
}
