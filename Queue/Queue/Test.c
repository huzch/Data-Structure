#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void TestQueue1()
{
	Queue q;
	//��ʼ��
	QueueInit(&q);
	//���
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	//��ӡ
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	//����
	QueueDestroy(&q);
}

int main()
{
	TestQueue1();
	return 0;
}