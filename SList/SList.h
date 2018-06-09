#ifndef __SList_h__
#define __SList_h__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

typedef struct SListNode
{
	DataType _data;
	struct SListNode* _next;
}SListNode;

SListNode* Buy_SListNode(DataType x);
void SList_Print(SListNode* pHead);
void SList_Destory(SListNode** ppHead);

void SList_PushBack(SListNode** ppHead, DataType x);
void SList_PopBack(SListNode** ppHead);
void SList_PushFront(SListNode** ppHead, DataType x);
void SList_PopFront(SListNode** ppHead);

SListNode* SList_Find(SListNode* pHead, DataType x);
void SList_Insert(SListNode** ppHead, SListNode* pos, DataType x);
void SList_Erase(SListNode** ppHead, SListNode* pos);

#endif __SList_h__