#ifndef RLIST_H
#define RLIST_H

typedef int ElemType;

struct rNode;
typedef struct rNode* prNode;
typedef prNode rList;

struct rNode{
	ElemType elem;
	prNode next;
	prNode prev;
};

rList rInit(rList rl);
prNode rInsert(ElemType elem,rList rl);
prNode rDelete(ElemType elem,rList rl);
void rPrintList(rList rl,int direction);





#endif
