#ifndef __DList_h__
#define __DList_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct DListNode
{
	DataType _data;
	struct DListNode* _prev;
	struct DListNode* _next;
}DListNode;

DListNode* BuyDListNode(DataType x);
DListNode* DListInit();
void DListDestroy(DListNode* head);
void DListPrint(DListNode* head);

void DListPushBack(DListNode* head, DataType x);
void DListPushFront(DListNode* head, DataType x);
void DListPopBack(DListNode* head);
void DListPopFront(DListNode* head);

DListNode* DListFind(DListNode* head, DataType x);
void DListInsert(DListNode* pos, DataType x);
void DListErase(DListNode* pos);

#endif __DList_h__