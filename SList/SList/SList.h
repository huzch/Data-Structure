#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//������
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

//��ӡ
void SLPrint(SLNode* phead);

//ͷ��
void SLPushFront(SLNode** pphead, SLDataType x);
//β��
void SLPushBack(SLNode** pphead, SLDataType x);
//ͷɾ
void SLPopFront(SLNode** pphead);
//βɾ
void SLPopBack(SLNode** pphead);

//����
SLNode* SLFind(SLNode* phead, SLDataType x);

//��posǰָ������
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x);
//��pos��ָ������
void SLInsertAfter(SLNode* pos, SLDataType x);

//��posָ��ɾ��
void SLErase(SLNode** pphead, SLNode* pos);
//��pos��ָ��ɾ��
void SLEraseAfter(SLNode* pos);

//����
void SLDestroy(SLNode* phead);
