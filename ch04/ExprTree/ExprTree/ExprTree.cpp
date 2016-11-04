#include "ExprTree.h"


Node* InitTreeNode(ElemType elem,lchild lc,rchild rc)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->elem = elem;
	n->lc = lc;
	n->rc = rc;	
	return n;
}


void PrintTree(Node *n)
{
	if (n == NULL)
	{
		return ;
	}
	if ( n->lc != NULL && n->rc != NULL)
	{
		printf("(");
	}
	
	PrintTree(n->rc);
	printf("%c ",n->elem);
	PrintTree(n->lc);

	if ( n->lc != NULL && n->rc != NULL)
	{
		printf(")");
	}
}