#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

TestDList1()
{
	DLNode* plist = DLInit();

	//尾插
	DLPushBack(plist, 1);
	DLPushBack(plist, 2);
	DLPushBack(plist, 3);
	DLPushBack(plist, 4);
	DLPushBack(plist, 5);

	//头插
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);

	//打印
	DLPrint(plist);
}

TestDList2()
{
	DLNode* plist = DLInit();

	//尾插
	DLPushBack(plist, 1);
	DLPushBack(plist, 2);
	DLPushBack(plist, 3);
	DLPushBack(plist, 4);
	DLPushBack(plist, 5);

	//头删
	DLPopFront(plist);
	DLPopFront(plist);
	DLPopFront(plist);

	//打印
	DLPrint(plist);
}

TestDList3()
{
	DLNode* plist = DLInit();

	//头插
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);

	//尾删
	DLPopBack(plist);
	DLPopBack(plist);
	DLPopBack(plist);

	//打印
	DLPrint(plist);
}


TestDList4()
{
	DLNode* plist = DLInit();
	//头插
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);
	//查找与修改
	DLNode* pos = DLFind(plist, 4);
	if (pos != NULL)
	{
		pos->data = 40;
		//在pos前指定插入
		DLInsert(pos, 100);
	}
	//打印
	DLPrint(plist);
}

TestDList5()
{
	DLNode* plist = DLInit();
	//头插
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);
	//查找与修改
	DLNode* pos = DLFind(plist, 4);
	if (pos != NULL)
	{
		pos->data = 40;
		//在pos指定删除
		DLErase(pos);
	}
	//打印
	DLPrint(plist);
}

TestDList6()
{
	DLNode* plist = DLInit();
	//尾插
	DLPushBack(plist, 1);
	DLPushBack(plist, 2);
	//头插
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	//打印
	DLPrint(plist);
	//销毁
	DLDestroy(plist);
	plist = NULL;
}

int main()
{
	TestDList6();
	return 0;
}