#include "SearchTree.h"

void DeleteTree(sNode sn)
{
	if (sn != NULL)
	{
		DeleteTree(sn->lc);
		DeleteTree(sn->rc);
		free(sn);
	}
}
sNode FindTree(sNode sn,int elem)
{
	if (sn != NULL)
	{
		if (sn->elem < elem)
		{
			return FindTree(sn->rc,elem);
		}
		else if (sn->elem > elem)
		{
			return FindTree(sn->lc,elem);
		}
		else
		{
			return sn;
		}
	}
}
sNode FindMax(sNode sn)
{
	if (sn != NULL)
	{
		while (sn->rc)
		{
			sn = sn->rc;
		}
		return sn;
	}
}
sNode FindMin(sNode sn)
{
	if (sn != NULL)
	{
		while (sn->lc)
		{
			sn = sn->lc;
		}
		return sn;
	}
}

sNode InitSNode(sNode sn,int elem)
{
	if (sn != NULL)
	{
		DeleteTree(sn);
		sn = NULL;
	}

	sn = (sNode)malloc(sizeof(struct SearchTreeNode));
	sn->elem = elem;
	sn->lc = NULL;
	sn->rc = NULL;
	return sn;

}

sNode InsertSNode(sNode sn,int elem)
{
	if (sn == NULL)
	{
		sn = (sNode)malloc(sizeof(struct SearchTreeNode));
		sn->elem = elem;
		sn->lc = NULL;
		sn->rc = NULL;
		return sn;
	}

	if (sn->elem < elem)
	{
		sn->rc = InsertSNode(sn->rc,elem);
	}
	else
	{
		sn->lc = InsertSNode(sn->lc,elem);
	}
	return sn;
}


void PrintSearchTree(sNode sn)
{
	if (sn != NULL)
	{
		PrintSearchTree(sn->lc);
		printf("%d ",sn->elem);
		PrintSearchTree(sn->rc);
	}
}