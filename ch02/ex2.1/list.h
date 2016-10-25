#ifndef LIST_H
#define LIST_H

typedef  int ElemType;

struct Node;

typedef struct Node* pNode;
typedef pNode List;

struct Node{
	ElemType elem;
	pNode next;
}*Head;

List Init(List l);
pNode Insert(ElemType elem,List l);
pNode Delete(ElemType elem,List l);
pNode Find(ElemType elem,List l);
void PrintList(List l);

#endif
