#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

DLNode* BuyDLNode(DLDataType x)
{
	DLNode* newnode = (DLNode*)malloc(sizeof(DLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

DLNode* DLInit()
{
	DLNode* phead = BuyDLNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void DLPrint(DLNode* phead)
{
	assert(phead);
	DLNode* cur = phead;

	printf("Guard");
	while (cur->next != phead)
	{
		cur = cur->next;
		printf("<==>%d", cur->data);
	}
	printf("\n");
}

bool DLEmpty(DLNode* phead)
{
	assert(phead);
	return phead == phead->next;
}

void DLPushBack(DLNode* phead, DLDataType x)
{
	assert(phead);
	DLInsert(phead, x);

	//DLNode* newnode = BuyDLNode(x);
	//DLNode* tail = phead->prev;
	//
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;
}

void DLPopBack(DLNode* phead)
{
	assert(phead);
	assert(!DLEmpty(phead));
	DLErase(phead->prev);

	//DLNode* tail = phead->prev;
	//DLNode* tailPrev = tail->prev;
	//
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;
}

void DLPushFront(DLNode* phead, DLDataType x)
{
	assert(phead);
	DLInsert(phead->next, x);

	//DLNode* newnode = BuyDLNode(x);
	//DLNode* first = phead->next;

	//newnode->next = first;
	//first->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
}

void DLPopFront(DLNode* phead)
{
	assert(phead);
	assert(!DLEmpty(phead));
	DLErase(phead->next);

	//DLNode* first = phead->next;
	//DLNode* second = first->next;

	//second->prev = phead;
	//phead->next = second;
	//free(first);
}

DLNode* DLFind(DLNode* phead, DLDataType x)
{
	assert(phead);
	DLNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

void DLInsert(DLNode* pos, DLDataType x)
{
	assert(pos);
	DLNode* newnode = BuyDLNode(x);
	DLNode* prev = pos->prev;

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void DLErase(DLNode* pos)
{
	assert(pos);
	DLNode* posPrev = pos->prev;
	DLNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

void DLDestroy(DLNode* phead)
{
	assert(phead);
	DLNode* cur = phead->next;

	while (cur != phead)
	{
		DLNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
}