#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

typedef BTNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestroy(Queue* pq);
//���
void QueuePush(Queue* pq, QDataType x);
//����
void QueuePop(Queue* pq);
//��ȡ��ͷԪ��
QDataType QueueFront(Queue* pq);
//��ȡ��βԪ��
QDataType QueueBack(Queue* pq);
//����������ЧԪ�ظ���
int QueueSize(Queue* pq);
//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);


