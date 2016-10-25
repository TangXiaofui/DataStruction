#ifndef DLIST_H
#define DLIST_H


typedef int dElemType;
struct dNode;
typedef struct dNode* pdNode;
typedef pdNode dList;

struct dNode{
	dElemType elem;
	pdNode next;
	pdNode prev;
}*dHead,*dTail;

dList dInit(dList l);
pdNode dInsert(dElemType elem,dList l);
pdNode dDelete(dElemType elem,dList l);
void dPrintList(dList l,int direction);

#endif

