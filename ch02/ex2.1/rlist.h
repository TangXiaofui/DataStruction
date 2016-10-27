#ifndef RLIST_H
#define RLIST_H

typedef int rElemType;

struct rNode;
typedef struct rNode* prNode;
typedef prNode rList;

struct rNode{
	rElemType elem;
	prNode next;
	prNode prev;
}*rHead,*rTail;

rList rInit(rList *rl);
prNode rInsert(rElemType elem,rList rl);
prNode rDelete(rElemType elem,rList rl);
void rPrintList(rList rl,int direction);





#endif
