#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void TestSList1()
{
	SLNode* plist = NULL;
	//ͷ��
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);
	//βɾ
	SLPopBack(&plist);
	SLPopBack(&plist);
	//��ӡ
	SLPrint(plist);
}

void TestSList2()
{
	SLNode* plist = NULL;
	//β��
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	//��ӡ
	SLPrint(plist);
}

void TestSList3()
{
	SLNode* plist = NULL;
	//β��
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	//βɾ
	SLPopBack(&plist);
	SLPopBack(&plist);
	//SLPopBack(&plist);
	//SLPopBack(&plist);
	//SLPopBack(&plist);
	//��ӡ
	SLPrint(plist);
}

void TestSList4()
{
	SLNode* plist = NULL;
	//β��
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 7);
	SLPushBack(&plist, 6);
	SLPushBack(&plist, 5);
	SLPushBack(&plist, 4);
	//ͷɾ
	SLPopFront(&plist);
	SLPopFront(&plist);
	SLPopFront(&plist);
	SLPopFront(&plist);
	//��ӡ
	SLPrint(plist);
}

void TestSList5()
{
	SLNode* plist = NULL;
	//ͷ��
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);
	//����
	SLNode* pos = SLFind(plist, 3);
	if (pos)
	{
		SLInsert(&plist, pos, 40);
		SLInsertAfter(pos, 50);
	}
	//��ӡ
	SLPrint(plist);
}

void TestSList6()
{
	SLNode* plist = NULL;
	//ͷ��
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);
	//����
	SLNode* pos = SLFind(plist, 3);
	if (pos)
	{
		SLErase(&plist, pos);
		SLEraseAfter(pos);
	}
	//��ӡ
	SLPrint(plist);
}

void TestSList7()
{
	SLNode* plist = NULL;
	//β��
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	//��ӡ
	SLPrint(plist);
	//����
	SLDestroy(plist);
	plist = NULL;
}

int main()
{
	TestSList7();
	return 0;
}