#ifndef EXPRTREE_H
#define EXPRTREE_H

#include <stdio.h>
#include <stdlib.h>
struct TreeNode;
typedef char ElemType;
typedef struct TreeNode *lchild ,*rchild, Node;

struct TreeNode{
	ElemType elem;
	lchild lc;
	rchild rc;
};

Node* InitTreeNode(ElemType elem,lchild lc,rchild rc);
void PrintTree(Node *n);

#endif