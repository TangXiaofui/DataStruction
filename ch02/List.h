#ifndef LIST_H
#define LIST_H


struct Node;
typedef int ElementType;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;


List MakeEmpty(List l);
int isEmpty(List l);
int isLast(Position pos, List l);
Position Find(ElementType elem,List l);
void Delete(ElementType elem,List l);
Position FindPreview(ElementType elem,List l);
void Insert(ElementType elem,List l,Position pos);
void DeleteList(List l);



struct Node{
	ElementType Element;
	Position next;
};




#endif
