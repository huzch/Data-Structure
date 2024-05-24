#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void TestQueue1()
{
	Queue q;
	//初始化
	QueueInit(&q);
	//入队
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	//打印
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	//销毁
	QueueDestroy(&q);
}

int main()
{
	TestQueue1();
	return 0;
}