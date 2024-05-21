#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"

void TestSeqList1()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);

	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPushFront(&s, 8);
	SLPushFront(&s, 9);
	SLPrint(&s);

	SLDestroy(&s);
}

void TestSeqList2()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);

	SLPushFront(&s, 5);
	SLPopBack(&s);
	SLPushFront(&s, 8);
	SLPopBack(&s);
	SLPrint(&s);

	SLDestroy(&s);
}

int main()
{
	TestSeqList2();
	return 0;
}