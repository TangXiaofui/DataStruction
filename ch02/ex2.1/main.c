#include <stdio.h>
#include "list.h"
#include "dlist.h"
#include "rlist.h"

int main(int argc,char* argv[])
{
	List l;
	l = Init(l);
	Insert(1,l);
	Insert(2,l);
	Insert(3,l);
	PrintList(l);	
	
	pNode tmp = Find(1,l);
	if(tmp == NULL)
		printf("find fail\n");
	else
		printf("find %d\n",tmp->elem);

	Delete(2,l);
	Delete(4,l);
	PrintList(l);

	printf("-------------------------\n");
	dList dl;
	dl = dInit(dl);
	dInsert(1,dl);
	dInsert(2,dl);
	dInsert(3,dl);
	dPrintList(dHead,1); 
	dPrintList(dTail,0);
	
	dDelete(1,dl);
	dDelete(3,dl);
	dPrintList(dHead,1);
	dPrintList(dTail,0);
	return 0;
}
