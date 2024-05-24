#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);
	psl->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (psl->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	psl->size = 0;
	psl->capacity = 4;
}

void SLDestroy(SL* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SLPrint(SL* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
}

static void CheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * psl->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity *= 2;
	}
}

void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	//CheckCapacity(psl);
	//psl->a[psl->size++] = x;
	SLInsert(psl, psl->size, x);
}

void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);
	//CheckCapacity(psl);
	//int end = psl->size - 1;
	//while (end >= 0)
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	end--;
	//}
	//psl->a[0] = x;
	//psl->size++;
	SLInsert(psl, 0, x);
}

void SLPopBack(SL* psl)
{
	assert(psl);
	//assert(psl->size > 0);
	//psl->size--;
	SLErase(psl, psl->size - 1);
}

void SLPopFront(SL* psl)
{
	assert(psl);
	//assert(psl->size > 0);
	//int start = 0;
	//while (start < psl->size - 1)
	//{
	//	psl->a[start] = psl->a[start + 1];
	//	start++;
	//}
	//psl->size--;
	SLErase(psl, 0);
}

void SLInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	CheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;
}

void SLErase(SL* psl, int pos)
{
	assert(psl);
	assert(pos >= 0 && pos < psl->size);
	int start = pos + 1;
	while (start < psl->size)
	{
		psl->a[start - 1] = psl->a[start];
		start++;
	}
	psl->size--;
}

int SLFind(SL* psl, SLDataType x)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SLModify(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos < psl->size);
	psl->a[pos] = x;
}//