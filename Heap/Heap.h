#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <windows.h>

typedef int HeapDateType;

typedef struct Heap
{
	HeapDateType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HeapDateType* a, size_t n);
void HeapMake(Heap* hp);

void HeapPush(Heap* hp, HeapDateType x);
void HeapPop(Heap* hp);

size_t GetHeapSize(Heap* hp);
size_t HeapEmpty(Heap* hp);
HeapDateType HeapTop(Heap* hp);

void HeapSort(Heap* hp);
void HeapAdjustDown(Heap* hp, int root);
void HeapAdjustUp(Heap* hp, int child);

void HeapPrint(Heap *hp);

void HeapTopK(HeapDateType* a, int size, int k);

#endif __HEAP_H__