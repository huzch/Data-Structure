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

//初始化
void STInit(ST* pst);
//销毁
void STDestroy(ST* pst);
//压栈
void STPush(ST* pst, STDataType x);
//出栈
void STPop(ST* pst);
//获取栈顶元素
STDataType STTop(ST* pst);
//检测栈是否为空
bool STEmpty(ST* pst);
//检测栈中有效元素个数
int STSize(ST* pst);
