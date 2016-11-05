#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

struct AVLTreeNode;
typedef struct AVLTreeNode *aNode;

struct AVLTreeNode{
	int Hight;
	int elem;
	aNode lc;
	aNode rc;
};

aNode InsertANode(aNode an,int elem);
int GetHeight(aNode an);
int MaxHeight(int x1,int x2);

aNode SingleRotateLeft(aNode an);
aNode SingleRotateRight(aNode an);
aNode DoubleRotateLeft(aNode an);
aNode DoubleRotateRight(aNode an);




#endif