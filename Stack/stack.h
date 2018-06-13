#ifndef __stack_h__
#define __stack_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define Initsize 5 //��ʼ�洢�ռ�
#define Increment 2 //ÿ������

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _size; //��Ч���ݸ��� 
	size_t _capacity; //���� 
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