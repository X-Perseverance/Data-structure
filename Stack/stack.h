#ifndef __stack_h__
#define __stack_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define Initsize 5 //初始存储空间
#define Increment 2 //每次增量

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _size; //有效数据个数 
	size_t _capacity; //容量 
}Stack;

void StackInit(Stack* s);
void CheckCapacity(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
void StackDestroy(Stack* s);

#endif __stack_h__