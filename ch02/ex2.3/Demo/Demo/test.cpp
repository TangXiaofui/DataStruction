#include <stdio.h>



int Unique(char buf[],int size)
{
	int oldsize = size;
	int i = 0 , j = 0;
	while( j++ < size )
		if (buf[i] != buf[j])
		{
			buf[++i] = buf[j];
		}
	size = i;
	return oldsize - size;
}

int main(int argc,char *argv[])
{
	char buf[] = "1112233";
	int size = sizeof(buf)/sizeof(buf[0]);
	
	printf("%s ,repeat = %d\n",buf,Unique(buf,size));


	return 0;
}