#include "AVLtree.h"

aNode InsertANode(aNode an,int elem)
{
	if (an == NULL)
	{
		an = (aNode)malloc(sizeof(struct AVLTreeNode));
		an->elem = elem;
		an->lc = an->rc = NULL;
		an->Hight = 0;
	}
	else
	{
		if (elem > an->elem)
		{
			an->rc = InsertANode(an->rc,elem);
			if (GetHeight(an->rc) - GetHeight(an->lc) >= 2)  //���ұ߲��룬�ұ߱Ƚ��� 
			{
				if (elem > an->rc->elem) //�Ƚϲ�������ڲ⻹����࣬��൥��ת���ڲ�˫��ת
				{
					an = SingleRotateRight(an);
				}
				else
				{
					an = DoubleRotateRight(an);
				}
			}
		}
		else if (elem < an->elem)
		{
			an->lc = InsertANode(an->lc,elem);
			if (GetHeight(an->lc) - GetHeight(an->rc) >= 2)
			{
				if (elem < an->lc->elem)
				{
					an = SingleRotateLeft(an);
				}
				else
				{
					an = DoubleRotateLeft(an);
				}
			}
		}
		//��ȾͲ��ò���
	}
	an->Hight = MaxHeight(GetHeight(an->lc),GetHeight(an->rc));	//���¸߶�
	return an;
}

int GetHeight(aNode an)
{
	if (an != NULL)
	{
		return an->Hight;
	}
	else
		return -1;
}

int MaxHeight(int x1,int x2)
{
	return x1 > x2 ? x1 :x2;
}

aNode SingleRotateLeft(aNode an)
{
	aNode a1 = an->lc;
	an->lc = a1->rc;
	a1->rc = an;

	an->Hight = MaxHeight(GetHeight(an->lc),GetHeight(an->rc)) + 1;
	a1->Hight = MaxHeight(GetHeight(a1->lc),GetHeight(a1->rc)) + 1;

	return a1;
}

aNode SingleRotateRight(aNode an)
{
	aNode a1 = an->rc;
	an->rc = a1->lc;
	a1->lc = an;

	an->Hight = MaxHeight(GetHeight(an->lc),GetHeight(an->rc)) + 1;
	a1->Hight = MaxHeight(GetHeight(a1->lc),GetHeight(a1->rc)) + 1;
	return a1;
}
aNode DoubleRotateLeft(aNode an)
{
	an->lc = SingleRotateRight(an->rc);
	an = SingleRotateLeft(an);

	return an;
}
aNode DoubleRotateRight(aNode an)
{
	an->rc = SingleRotateLeft(an->rc);

	return SingleRotateRight(an);
}