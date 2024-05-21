#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SLPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* BuySLNode(SLDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SLPushFront(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	SLNode* newnode = BuySLNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLPushBack(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	//1.空链表
	//2.非空链表
	SLNode* newnode = BuySLNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
}

void SLPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	//空链表
	//一个节点
	//多个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;

		//SLNode* prev = NULL;
		//SLNode* tail = *pphead;
		//while (tail->next)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}
		//free(tail);
		//prev->next = NULL;
	}
}

SLNode* SLFind(SLNode* phead, SLDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLNode* newnode = BuySLNode(x);
		newnode->next = pos;
		prev->next = newnode;
	}
}

void SLInsertAfter(SLNode* pos, SLDataType x)
{
	assert(pos);
	SLNode* newnode = BuySLNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)
	{
		SLPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SLEraseAfter(SLNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLNode* next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

//void SLDestroy(SLNode** pphead)
//{
//	assert(pphead);
//	SLNode* cur = *pphead;
//	while (cur)
//	{
//		SLNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	*pphead = NULL;
//}

void SLDestroy(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
}