#ifndef __RPN_h__
#define __RPN_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h> 

#define Initsize 5 //初始存储空间
#define Increment 2 //每次增量

typedef struct CStack //字符栈
{
	char* _array;
	size_t _size; //有效数据个数 
	size_t _capacity; //容量 
}CStack;

typedef struct IStack //数字栈
{
	int* _array;
	size_t _size;
	size_t _capacity;
}IStack;

void CStackInit(CStack* s);
void CCheckCapacity(CStack* s);
void CStackPush(CStack* s, char x);
void CStackPop(CStack* s);
char CStackTop(CStack* s);
int CStackEmpty(CStack* s);

void IStackInit(IStack* s);
void ICheckCapacity(IStack* s);
void IStackPush(IStack* s, int x);
void IStackPop(IStack* s);
int IStackTop(IStack* s);

int Precede(char top, char newnode);
void Infix_to_Suffix(char* p, char *arr);
int Count_Suffix(char *arr);

#endif __RPN_h__