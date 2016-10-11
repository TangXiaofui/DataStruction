#include <stdio.h>

void bulb_sort(int array[],int len)
{
	int i,j,tmp;
	for(i = 0; i < len; i++)
	{
		for(j = i+1;j < len ; j++)
		{
			if(array[j] > array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	for(i =0 ; i < len;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");

}



void short_sort(int array[],int len,int k)
{
	int num = k;
	bulb_sort(array,k);
	int i = 0;
	for(i = k; i < len;i++)
	{
		if(array[i] <= array[k-1])
		{
			continue;
		}
		int j = 0;
		for(j = 0; j < k;j++)
		{
			if(array[j] >= array[i])
			{
				continue;
			}

			int z;
			for(z=k-1;z > j ;z--)
			{
				array[z] = array[z-1];
			}
			array[j] = array[i];
			break;
			}
		
	}
 	for(i =0 ; i < k;i++)
        {
                printf("%d ",array[i]);
        }
        printf("\n");

}

int main(int argc,char *argv[])
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(array)/sizeof(array[0]);
	//bulb_sort(array,len);
	short_sort(array,len,4);	

	return 0;
}
