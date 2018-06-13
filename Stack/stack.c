#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

//初始化
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

//扩容
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

//入栈
void StackPush(Stack* s, DataType x)
{
	assert(s);
	CheckCapacity(s);
	s->_array[s->_size] = x;
	s->_size++;
}

//出栈
void StackPop(Stack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("该栈为空\n");
	}
	else
	{
		s->_size--;
	}
}

//获取栈顶元素
DataType StackTop(Stack* s)
{
	assert(s);
	assert(s->_size > 0);
	return s->_array[(s->_size) - 1];
}

//栈长度
size_t StackSize(Stack* s)
{
	assert(s);
	return s->_size;
}

//判空
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

//销毁
void StackDestroy(Stack* s)
{
	free(s->_array);
	s->_size = 0;
	s->_capacity = 0;
}