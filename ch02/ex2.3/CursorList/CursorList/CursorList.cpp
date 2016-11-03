// CursorList.cpp : 定义控制台应用程序的入口点。
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

