#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//��ʼ��
void STInit(ST* pst);
//����
void STDestroy(ST* pst);
//ѹջ
void STPush(ST* pst, STDataType x);
//��ջ
void STPop(ST* pst);
//��ȡջ��Ԫ��
STDataType STTop(ST* pst);
//���ջ�Ƿ�Ϊ��
bool STEmpty(ST* pst);
//���ջ����ЧԪ�ظ���
int STSize(ST* pst);
