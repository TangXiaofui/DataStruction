#include <stdio.h>


void printDigit(int num)
{
	printf("%d",num);
}

void printOut(int num)
{
	if( num == 0)
		return ;
	printOut(num/10);
	printDigit(num%10);
}


int main(int argc,char*argv[])
{
	printOut(54321);
	printf("\n");
	return 0;
}
