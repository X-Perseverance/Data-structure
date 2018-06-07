// µœ÷æ≤Ã¨À≥–Ú±Ì
#ifndef __SeqList_h__
#define __SeqList_h__

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>

#define N 5

typedef int DataType;

typedef struct SeqList
{
	DataType a[N];
	size_t size;
}SeqList;

void SeqList_Init(SeqList *pSeq);
void SeqList_Print(SeqList *pSeq);

void SeqList_Insert(SeqList *pSeq, size_t pos, DataType x);
void SeqList_Delete(SeqList *pSeq, size_t pos);

void SeqList_Remove(SeqList *pSeq, DataType x);
void SeqList_RemoveAll(SeqList *pSeq, DataType x);

void SeqList_Search(SeqList *pSeq, DataType x);
void SeqList_Modify(SeqList *pSeq, size_t pos, DataType x);

void Bubble_Sort(SeqList *pSeq);
void Select_Sort(SeqList *pSeq);
void Binary_Search(SeqList *pSeq, DataType x);

#endif   //__SeqList_h__