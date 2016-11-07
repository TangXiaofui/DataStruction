#include <stdio.h>
#include "AVLtree.h"


int main(int argc,char *argv[])
{
	aNode an = NULL;
	an = InsertANode(an,5);
	an = InsertANode(an,4);
	an = InsertANode(an,3);
	an = InsertANode(an,2);
	an = InsertANode(an,1);

	PrintAnodePrev(an);
	printf("\n");

	PrintAnodeMid(an);
	printf("\n");

	PrintAnodeBack(an);
	printf("\n");
	return 0;
}