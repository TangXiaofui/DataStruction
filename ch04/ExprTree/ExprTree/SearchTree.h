#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include <stdio.h>
#include <stdlib.h>

struct SearchTreeNode;

typedef struct SearchTreeNode *sNode;

struct SearchTreeNode
{
	int elem;
	sNode lc;
	sNode rc;
};

void DeleteTree(sNode sn);
sNode FindTree(sNode sn,int elem);
sNode FindMax(sNode sn);
sNode FindMin(sNode sn);
sNode InitSNode(sNode sn,int elem);
sNode InsertSNode(sNode sn,int elem);
void PrintSearchTree(sNode sn);

#endif