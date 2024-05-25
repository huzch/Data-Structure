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

//��ʼ��
void HPInit(HP* php);
//����
void HPDestroy(HP* php);
//���
void HPPush(HP* php, HPDataType x);
//ɾ���Ѷ�Ԫ��
void HPPop(HP* php);
//�ж϶��Ƿ�Ϊ��
bool HPEmpty(HP* php);
//��ȡ�Ѷ�Ԫ��
HPDataType HPTop(HP* php);
//��ȡ�ѵ�Ԫ�ظ���
int HPSize(HP* php);

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);