#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//静态顺序表
//#define N 10
//typedef int SLDataType;
//
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;
//}SL;


//动态顺序表
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//存储的有效数据的个数
	int capacity;//容量
}SL;

//初始化
void SLInit(SL* psl);
//销毁
void SLDestroy(SL* psl);
//打印
void SLPrint(SL* psl);


//尾插
void SLPushBack(SL* psl, SLDataType x);
//头插
void SLPushFront(SL* psl, SLDataType x);
//尾删
void SLPopBack(SL* psl);
//头删
void SLPopFront(SL* psl);

//指定插入
void SLInsert(SL* psl, int pos, SLDataType x);
//指定删除
void SLErase(SL* psl, int pos);

//查找
int SLFind(SL* psl, SLDataType x);
//修改
void SLModify(SL* psl, int pos, SLDataType x);

