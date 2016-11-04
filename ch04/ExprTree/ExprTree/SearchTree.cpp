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
	return NULL;
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

sNode DeleteElem(sNode sn,int elem)
{
	if (sn == NULL)
	{
		return NULL;
	}
	else
	{
		if (elem > sn->elem)
		{
			sn->rc = DeleteElem(sn->rc,elem);
		}
		else if (elem < sn->elem)
		{
			sn->lc = DeleteElem(sn->lc,elem);
		}
		else
		{
			if (sn->lc && sn->rc)
			{
				sNode temp = FindMin(sn->rc);
				sn->elem = temp->elem;
				sn->rc = DeleteElem(sn->rc,temp->elem);
			}
			else
			{
				sNode dn = sn;
				//下面这一段必须要 == NULL ，否则要写成如下形式
				/*
				if (sn->lc != NULL)
				{
					sn = sn->lc;
				}
				else if (sn->rc != NULL)
				{
					sn = sn->rc;
				}
				else //两边都为空
				{
					sn = NULL;
				}
				*/
				if (sn->lc == NULL)
				{
					sn = sn->rc;
				}
				else if (sn->rc == NULL)
				{
					sn = sn->lc;
				}
				free(dn);
			}
		}
	}
	return sn;

}