#include <stdio.h>
#include "ExprTree.h"
#include "Stack.h"
#include "SearchTree.h"

void PolandToTree(stack s,char expr[])
{
	int i = 0;
	while(expr[i])
	{
		if ( expr[i] >= 'a' && expr[i] <= 'z' || (expr[i] >= 'A' && expr[i] <= 'Z') )
		{
			Node *n = InitTreeNode(expr[i],NULL,NULL);
			Push(s,n);
		}
		else
		{
			Node *n1 = Pop(s);
			Node *n2 = Pop(s);
			Node *n = InitTreeNode(expr[i],n1,n2);
			Push(s,n);
		}
		i++;
	}
}

int main(int argc,char*argv[])
{
// 	char buf[] = "ab+cde+**";
// 	stack s;
// 	InitStack(&s,20);
// 	PolandToTree(s,buf);
// 	PrintTree(Pop(s));
	sNode sn = NULL;
	sn = InitSNode(sn,5);
	InsertSNode(sn,1);
	InsertSNode(sn,4);
	InsertSNode(sn,8);
	InsertSNode(sn,3);
	InsertSNode(sn,6);
	InsertSNode(sn,11);
	PrintSearchTree(sn);

	printf("\n");
	DeleteElem(sn,3);
	PrintSearchTree(sn);




	return 0;
}