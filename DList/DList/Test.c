#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

TestDList1()
{
	DLNode* plist = DLInit();

	//β��
	DLPushBack(plist, 1);
	DLPushBack(plist, 2);
	DLPushBack(plist, 3);
	DLPushBack(plist, 4);
	DLPushBack(plist, 5);

	//ͷ��
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);

	//��ӡ
	DLPrint(plist);
}

TestDList2()
{
	DLNode* plist = DLInit();

	//β��
	DLPushBack(plist, 1);
	DLPushBack(plist, 2);
	DLPushBack(plist, 3);
	DLPushBack(plist, 4);
	DLPushBack(plist, 5);

	//ͷɾ
	DLPopFront(plist);
	DLPopFront(plist);
	DLPopFront(plist);

	//��ӡ
	DLPrint(plist);
}

TestDList3()
{
	DLNode* plist = DLInit();

	//ͷ��
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);

	//βɾ
	DLPopBack(plist);
	DLPopBack(plist);
	DLPopBack(plist);

	//��ӡ
	DLPrint(plist);
}


TestDList4()
{
	DLNode* plist = DLInit();
	//ͷ��
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);
	//�������޸�
	DLNode* pos = DLFind(plist, 4);
	if (pos != NULL)
	{
		pos->data = 40;
		//��posǰָ������
		DLInsert(pos, 100);
	}
	//��ӡ
	DLPrint(plist);
}

TestDList5()
{
	DLNode* plist = DLInit();
	//ͷ��
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	DLPushFront(plist, 3);
	DLPushFront(plist, 4);
	DLPushFront(plist, 5);
	//�������޸�
	DLNode* pos = DLFind(plist, 4);
	if (pos != NULL)
	{
		pos->data = 40;
		//��posָ��ɾ��
		DLErase(pos);
	}
	//��ӡ
	DLPrint(plist);
}

TestDList6()
{
	DLNode* plist = DLInit();
	//β��
	DLPushBack(plist, 1);
	DLPushBack(plist, 2);
	//ͷ��
	DLPushFront(plist, 1);
	DLPushFront(plist, 2);
	//��ӡ
	DLPrint(plist);
	//����
	DLDestroy(plist);
	plist = NULL;
}

int main()
{
	TestDList6();
	return 0;
}