#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DLDataType;
typedef struct DListNode
{
	struct DListNode* prev;
	struct DListNode* next;
	DLDataType data;
}DLNode;

//��ʼ��
DLNode* DLInit();
//��ӡ
void DLPrint(DLNode* phead);
//����
void DLDestroy(DLNode* phead);

//��������Ƿ�Ϊ��
bool DLEmpty(DLNode* phead);
//β��
void DLPushBack(DLNode* phead, DLDataType x);
//βɾ
void DLPopBack(DLNode* phead);
//ͷ��
void DLPushFront(DLNode* phead, DLDataType x);
//ͷɾ
void DLPopFront(DLNode* phead);

//����
DLNode* DLFind(DLNode* phead, DLDataType x);

//��posǰָ������
void DLInsert(DLNode* pos, DLDataType x);
//��posָ��ɾ��
void DLErase(DLNode* pos);