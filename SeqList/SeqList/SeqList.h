#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��̬˳���
//#define N 10
//typedef int SLDataType;
//
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;
//}SL;


//��̬˳���
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//�洢����Ч���ݵĸ���
	int capacity;//����
}SL;

//��ʼ��
void SLInit(SL* psl);
//����
void SLDestroy(SL* psl);
//��ӡ
void SLPrint(SL* psl);


//β��
void SLPushBack(SL* psl, SLDataType x);
//ͷ��
void SLPushFront(SL* psl, SLDataType x);
//βɾ
void SLPopBack(SL* psl);
//ͷɾ
void SLPopFront(SL* psl);

//ָ������
void SLInsert(SL* psl, int pos, SLDataType x);
//ָ��ɾ��
void SLErase(SL* psl, int pos);

//����
int SLFind(SL* psl, SLDataType x);
//�޸�
void SLModify(SL* psl, int pos, SLDataType x);

