#include <stdio.h>

void calTri(int n)
{
	int i ,sum;
	for(i = 1,sum =0; i <= n ;i++  )
		sum += i * i * i;
	
	printf("sum = %d\n",sum);
}

void calMax_1(int array[],int n)
{
	int i,j,k,max = 0,tmp;
	for(i = 0; i < n; i++)
	{
		tmp = 0;
		for(j = i ; j < n ;j++ )
		{
			tmp += array[j];
			if(tmp > max)
			{
				max = tmp;
			}
		}
	}
	printf("max = %d\n",max);
}

int calMax_2(int array[],int left,int right)
{
	if(left == right)
	{
		return array[left];
	}
	int lmax = 0,rmax = 0;
	int n = (right + left)/2; 
	lmax = calMax_2(array,left,n);
	rmax = calMax_2(array,n+1,right);
	
	int max = 0;
	if(lmax > rmax)
		max = lmax;
	else
		max = rmax;
	int i = 0;
	int sum = array[n];
	if(n < right)
	{
		for(i = 1; i <= right-n ;i++)
		{
			sum+= array[n+i];
			if(n-i >= 0)
				sum += array[n-i];
			if(max < sum)
				max = sum;
		}
	}
	return max;
}

void calMax_3(int array[],int n)
{
	int i = 0;
	int sum = 0;
	int max = 0;
	for(i = 0; i < n ;i++)
	{
		sum += array[i];
		if(sum  < 0)
			sum = 0;
		if(sum > max)
			max = sum;	
	}
	printf("max = %d\n",max);
}


int main(int argc,char *argv[])
{
	int array[] = {-2,11,-4,13,-5,-2};
	int n = sizeof(array)/sizeof(array[0]);
	//calMax_1(array,n);
//	printf("max = %d\n",calMax_2(array,0,n-1));
	calMax_3(array,n);
	return 0;
}
