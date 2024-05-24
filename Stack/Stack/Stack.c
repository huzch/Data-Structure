#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->top = 0;//top指向栈顶元素的下一个位置
	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->top = pst->capacity = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newCapacity * sizeof(STDataType));

		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		pst->a = tmp;
		pst->capacity = newCapacity;
	}

	pst->a[pst->top++] = x;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));

	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));

	return pst->a[pst->top - 1];
}

bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}