// CursorList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CursorList.h"
#include "Stack.h"
#define ADD 0
#define MUL 1
#define LP  2
char symbol[]={'+','*','('};
int _tmain(int argc, _TCHAR* argv[])
{
// 	InitCursorList();
// 	Pos p = CursorAlloc();
// 	list[p].next = 0;
// 	InsertElem(p,1);
// 	InsertElem(p,2);
// 	InsertElem(p,3);
// 	PrintElem(p);
// 	DeleteElem(p,1);
// 	PrintElem(p);

// 	Stack s;
// 	InitStack(&s,20);
// 	char cInput[20];
// 	memset(cInput,0,20);
// 	scanf("%s",cInput);
// 	int i = 0,flag = 0;
// 	while (cInput[i])
// 	{
// 		switch (cInput[i])
// 		{
// 			case '[':Push(s,cInput[i]);break;
// 			case '(':Push(s,cInput[i]);break;
// 			case ')':
// 				if (Top(s) == '(')
// 				{
// 					Pop(s);
// 				}
// 				break;
// 			case ']':
// 				if (Top(s) == '[')
// 				{
// 					Pop(s);
// 				}
// 				break;
// 		}
// 		i++;
// 	}
// 	if (Pop(s) == -1)
// 	{
// 		printf("success\n");
// 	}
// 	else
// 		printf("fail\n");



	Stack s;
	InitStack(&s,20);
	char expr[] = "a+b*c+(d*e+f)*g";
	int i = 0;
	int flag = 0;
	while (expr[i])
	{
		if ((expr[i] >= 'a' && expr[i] <= 'z') || (expr[i] >= 'A' && expr[i] <= 'Z'))
		{
			printf("%c ",expr[i]);
		}
		else
		{
			switch(expr[i])
			{
				case '+':
					if (Top(s) == -1)
						Push(s,ADD);
					else
					{
						while(1)
						{
							int sym = Top(s);
							if (sym != LP)
							{
								if (sym >= ADD)
								{
									printf("%c ",symbol[Pop(s)]);
								}
								else
								{
									break;
								}
							}
							else
								break;
						}
						Push(s,ADD);
					}		
				break;
				case '*':
					if (Top(s) == -1)
						Push(s,MUL);
					else
					{
						while(1)
						{
							int sym = Top(s);
							if (sym != LP)
							{
								if (sym >= MUL)
								{
									printf("%c ",symbol[Pop(s)]);
								}
								else
								{
									break;
								}
							}
							else
							{
								break;
							}
						}
						Push(s,MUL);
					}		
				break;
				case '(':
					Push(s,LP);
				break;
				case ')':
					while(1)
					{
						if (Top(s) != LP)
						{
							printf("%c ",symbol[Pop(s)]);
						}
						else
						{
							flag = 1;
							Pop(s);
							break;
						}
						if (Top(s) == -1)
						{
							break;
						}
					}
					if (flag != 1)
					{
						goto err;
					}		
				break;
				default:
					break;
			}
		}
		i++;
	}
	while (Top(s) != -1)
	{
		printf("%c ",symbol[Pop(s)]);
	}

	return 0;
err:
	printf("\n---------------fail");
	return 0;
}

