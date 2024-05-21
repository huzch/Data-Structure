#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void TestSList1()
{
	SLNode* plist = NULL;
	//Õ∑≤Â
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);
	//Œ≤…æ
	SLPopBack(&plist);
	SLPopBack(&plist);
	//¥Ú”°
	SLPrint(plist);
}

void TestSList2()
{
	SLNode* plist = NULL;
	//Œ≤≤Â
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	//¥Ú”°
	SLPrint(plist);
}

void TestSList3()
{
	SLNode* plist = NULL;
	//Œ≤≤Â
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	//Œ≤…æ
	SLPopBack(&plist);
	SLPopBack(&plist);
	//SLPopBack(&plist);
	//SLPopBack(&plist);
	//SLPopBack(&plist);
	//¥Ú”°
	SLPrint(plist);
}

void TestSList4()
{
	SLNode* plist = NULL;
	//Œ≤≤Â
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 7);
	SLPushBack(&plist, 6);
	SLPushBack(&plist, 5);
	SLPushBack(&plist, 4);
	//Õ∑…æ
	SLPopFront(&plist);
	SLPopFront(&plist);
	SLPopFront(&plist);
	SLPopFront(&plist);
	//¥Ú”°
	SLPrint(plist);
}

void TestSList5()
{
	SLNode* plist = NULL;
	//Õ∑≤Â
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);
	//≤È’“
	SLNode* pos = SLFind(plist, 3);
	if (pos)
	{
		SLInsert(&plist, pos, 40);
		SLInsertAfter(pos, 50);
	}
	//¥Ú”°
	SLPrint(plist);
}

void TestSList6()
{
	SLNode* plist = NULL;
	//Õ∑≤Â
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);
	//≤È’“
	SLNode* pos = SLFind(plist, 3);
	if (pos)
	{
		SLErase(&plist, pos);
		SLEraseAfter(pos);
	}
	//¥Ú”°
	SLPrint(plist);
}

void TestSList7()
{
	SLNode* plist = NULL;
	//Œ≤≤Â
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	//¥Ú”°
	SLPrint(plist);
	//œ˙ªŸ
	SLDestroy(plist);
	plist = NULL;
}

int main()
{
	TestSList7();
	return 0;
}