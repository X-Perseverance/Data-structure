#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

//��ʼ��
void StackInit(Stack* s)
{
	assert(s);
	s->_size = 0;
	s->_capacity = Initsize;
	s->_array = (SDataType*)malloc(Initsize*sizeof(SDataType));
	if (s->_array == NULL)
	{
		perror("StackInit");
		return;
	}
	memset(s->_array, 0, s->_capacity * sizeof(SDataType));
}

//����
void CheckCapacity(Stack* s)
{
	assert(s);
	if (s->_size >= s->_capacity)
	{
		SDataType* ptr = (SDataType*)realloc(s->_array, (s->_capacity + Increment)*sizeof(SDataType));
		if (ptr == NULL)
		{
			perror("CheckCapacity");
		}
		else
		{
			s->_array = ptr;
			s->_capacity += Increment;
		}
	}
}

//��ջ
void StackPush(Stack* s, SDataType x)
{
	assert(s);
	CheckCapacity(s);
	s->_array[s->_size] = x;
	s->_size++;
}

//��ջ
void StackPop(Stack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		return;
	}
	else
	{
		s->_size--;
	}
}

//��ȡջ��Ԫ��
SDataType StackTop(Stack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		return NULL;
	}
	return s->_array[(s->_size) - 1];
}

//�п�
int StackEmpty(Stack* s)
{
	assert(s);
	if (s->_size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}