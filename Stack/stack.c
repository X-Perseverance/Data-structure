#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

//��ʼ��
void StackInit(Stack* s)
{
	assert(s);
	s->_size = 0;
	s->_capacity = Initsize;
	s->_array = (DataType*)malloc(Initsize*sizeof(DataType));
	if (s->_array == NULL)
	{
		perror("StackInit");
		return;
	}
	memset(s->_array, 0, s->_capacity * sizeof(DataType));
}

//����
void CheckCapacity(Stack* s)
{
	assert(s);
	if (s->_size >= s->_capacity)
	{
		DataType* ptr = (DataType*)realloc(s->_array, (s->_capacity + Increment)*sizeof(DataType));
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
void StackPush(Stack* s, DataType x)
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
		printf("��ջΪ��\n");
	}
	else
	{
		s->_size--;
	}
}

//��ȡջ��Ԫ��
DataType StackTop(Stack* s)
{
	assert(s);
	assert(s->_size > 0);
	return s->_array[(s->_size) - 1];
}

//ջ����
size_t StackSize(Stack* s)
{
	assert(s);
	return s->_size;
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

//����
void StackDestroy(Stack* s)
{
	free(s->_array);
	s->_size = 0;
	s->_capacity = 0;
}