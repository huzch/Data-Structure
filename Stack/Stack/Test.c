#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void TestStack1()
{
	ST st;
	//初始化
	STInit(&st);
	//压栈
	STPush(&st, 1);
	STPush(&st, 2);
	printf("%d\n", STTop(&st));
	STPop(&st);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	//打印
	while (!STEmpty(&st))
	{
		printf("%d\n", STTop(&st));
		STPop(&st);
	}
	//销毁
	STDestroy(&st);
}

int main()
{
	TestStack1();
	return 0;
}