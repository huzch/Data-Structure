#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//单链表
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

//打印
void SLPrint(SLNode* phead);

//头插
void SLPushFront(SLNode** pphead, SLDataType x);
//尾插
void SLPushBack(SLNode** pphead, SLDataType x);
//头删
void SLPopFront(SLNode** pphead);
//尾删
void SLPopBack(SLNode** pphead);

//查找
SLNode* SLFind(SLNode* phead, SLDataType x);

//在pos前指定插入
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x);
//在pos后指定插入
void SLInsertAfter(SLNode* pos, SLDataType x);

//在pos指定删除
void SLErase(SLNode** pphead, SLNode* pos);
//在pos后指定删除
void SLEraseAfter(SLNode* pos);

//销毁
void SLDestroy(SLNode* phead);
