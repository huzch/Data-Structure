#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//初始化
void HPInit(HP* php);
//销毁
void HPDestroy(HP* php);
//入堆
void HPPush(HP* php, HPDataType x);
//删除堆顶元素
void HPPop(HP* php);
//判断堆是否为空
bool HPEmpty(HP* php);
//获取堆顶元素
HPDataType HPTop(HP* php);
//获取堆的元素个数
int HPSize(HP* php);

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);