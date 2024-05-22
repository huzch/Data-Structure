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

//初始化
DLNode* DLInit();
//打印
void DLPrint(DLNode* phead);
//销毁
void DLDestroy(DLNode* phead);

//检测链表是否为空
bool DLEmpty(DLNode* phead);
//尾插
void DLPushBack(DLNode* phead, DLDataType x);
//尾删
void DLPopBack(DLNode* phead);
//头插
void DLPushFront(DLNode* phead, DLDataType x);
//头删
void DLPopFront(DLNode* phead);

//查找
DLNode* DLFind(DLNode* phead, DLDataType x);

//在pos前指定插入
void DLInsert(DLNode* pos, DLDataType x);
//在pos指定删除
void DLErase(DLNode* pos);