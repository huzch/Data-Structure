#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void TestStack1()
{
	ST st;
	//��ʼ��
	STInit(&st);
	//ѹջ
	STPush(&st, 1);
	STPush(&st, 2);
	printf("%d\n", STTop(&st));
	STPop(&st);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	//��ӡ
	while (!STEmpty(&st))
	{
		printf("%d\n", STTop(&st));
		STPop(&st);
	}
	//����
	STDestroy(&st);
}

int main()
{
	TestStack1();
	return 0;
}