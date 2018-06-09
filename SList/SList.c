#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//建立结点
SListNode* Buy_SListNode(DataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

//打印
void SList_Print(SListNode* pHead)
{
	if (pHead == NULL)
	{
		printf("该链表为空！\n");
	}
	else
	{
		SListNode* cur = pHead;
		while (cur)
		{
			printf("%d->", cur->_data);
			cur = cur->_next;
		}
		printf("NULL\n");
	}
}

//销毁
void SList_Destory(SListNode** ppHead)
{
	if (*ppHead == NULL)
	{
		printf("该链表为空！\n");
	}
	else
	{
		SListNode* cur = *ppHead;
		SListNode* tail = NULL;
		while (cur)
		{
			tail = cur->_next;
			free(cur);
			cur = tail;
		}
		*ppHead = NULL;
		printf("销毁成功！\n");
	}
}

//尾插
void SList_PushBack(SListNode **ppHead, DataType x)
{
	assert(ppHead);
	if (*ppHead == NULL)
	{
		*ppHead = Buy_SListNode(x);
	}
	else
	{
		SListNode * cur = *ppHead;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = Buy_SListNode(x);
	}
}

//尾删
void SList_PopBack(SListNode** ppHead)
{
	assert(ppHead);
	if (*ppHead == NULL)
	{
		printf("该链表为空！\n");
	}
	else if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		SListNode * prev = *ppHead;
		SListNode * cur = *ppHead;
		while (cur->_next != NULL)
		{
			prev = cur; // 记录前一个结点
			cur = cur->_next;
		}
		free(cur);
		prev->_next = NULL;
	}
}

//头插
void SList_PushFront(SListNode** ppHead, DataType x)
{
	assert(ppHead);
	if (*ppHead == NULL)
	{
		*ppHead = Buy_SListNode(x);
	}
	else
	{
		SListNode * newHead = Buy_SListNode(x);
		newHead->_next = *ppHead;
		*ppHead = newHead;
	}
}

//头删
void SList_PopFront(SListNode** ppHead)
{
	assert(ppHead);
	if (*ppHead == NULL)
	{
		printf("该链表为空！\n");
	}
	else if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		SListNode * cur = (*ppHead)->_next;
		free(*ppHead);
		*ppHead = cur;
	}
}

//查找
SListNode* SList_Find(SListNode* pHead, DataType x)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	SListNode * cur = pHead;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//插入
void SList_Insert(SListNode** ppHead, SListNode* pos, DataType x)
{
	assert(ppHead);
	if (pos == *ppHead)
	{
		SList_PushFront(ppHead, x);
	}
	else
	{
		SListNode * cur = *ppHead;
		SListNode * newNode = Buy_SListNode(x);
		while (cur->_next != pos)
		{
			cur = cur->_next;
		}
		newNode->_next = pos;
		cur->_next = newNode;
	}
}

//删除
void SList_Erase(SListNode** ppHead, SListNode* pos)
{
	assert(ppHead);
	if (*ppHead == pos)
	{
		SList_PopFront(ppHead);
	}
	else
	{
		SListNode *cur = *ppHead;
		while (cur->_next != pos)
		{
			cur = cur->_next;
		}
		cur->_next = pos->_next;
		free(pos);
	}
}