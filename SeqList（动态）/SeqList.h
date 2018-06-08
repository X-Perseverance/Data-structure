//实现动态顺序表
#ifndef __SeqList_h__
#define __SeqList_h__

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <windows.h>

typedef int DataType;

typedef struct SeqList
{
	DataType* _a;
	size_t _size; //有效数据个数 
	size_t _capacity; //容量 
}SeqList;

void SeqInit(SeqList* pSeq);
void CheckCapacity(SeqList* pSeq);
void SeqPrint(SeqList* pSeq);
void SeqDestroy(SeqList* pSeq);

void SeqPushBack(SeqList* pSeq, DataType x);
void SeqPopBack(SeqList* pSeq);
void SeqPushFront(SeqList* pSeq, DataType x);
void SeqPopFront(SeqList* pSeq);

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);
void SeqErase(SeqList* pSeq, size_t pos);

int SeqFind(SeqList* pSeq, DataType x);
void SeqModify(SeqList* pSeq, size_t pos, DataType x);

void BubbleSort(SeqList* pSeq);
void SelectSort(SeqList* pSeq);
int BinarySearch(SeqList* pSeq, DataType x);

#endif //__SeqList_h__