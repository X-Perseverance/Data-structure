#ifndef __RPN_h__
#define __RPN_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h> 

#define Initsize 5 //��ʼ�洢�ռ�
#define Increment 2 //ÿ������

typedef struct CStack //�ַ�ջ
{
	char* _array;
	size_t _size; //��Ч���ݸ��� 
	size_t _capacity; //���� 
}CStack;

typedef struct IStack //����ջ
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