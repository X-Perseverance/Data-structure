#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

int main()
{
	Stack s;
	StackInit(&s);
	for (int i = 1; i < 10; i++)
	{
		StackPush(&s, i);
	}
	printf("栈顶元素为：%d\n", StackTop(&s));

	if (StackEmpty(&s))
	{
		printf("栈长度为：%d\n", StackSize(&s));
	}
	else
	{
		printf("栈长度为0\n");
	}

	StackPop(&s);
	printf("栈顶元素为：%d\n", StackTop(&s));

	if (StackEmpty(&s))
	{
		printf("栈长度为：%d\n", StackSize(&s));
	}
	else
	{
		printf("栈长度为0\n");
	}

	StackDestroy(&s);

	system("pause");
	return 0;
}