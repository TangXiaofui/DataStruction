// CursorList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CursorList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	InitCursorList();
	Pos p = CursorAlloc();
	list[p].next = 0;
	InsertElem(p,1);
	InsertElem(p,2);
	InsertElem(p,3);
	PrintElem(p);
	DeleteElem(p,1);
	PrintElem(p);


	return 0;
}

