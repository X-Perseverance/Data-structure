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
	printf("ջ��Ԫ��Ϊ��%d\n", StackTop(&s));

	if (StackEmpty(&s))
	{
		printf("ջ����Ϊ��%d\n", StackSize(&s));
	}
	else
	{
		printf("ջ����Ϊ0\n");
	}

	StackPop(&s);
	printf("ջ��Ԫ��Ϊ��%d\n", StackTop(&s));

	if (StackEmpty(&s))
	{
		printf("ջ����Ϊ��%d\n", StackSize(&s));
	}
	else
	{
		printf("ջ����Ϊ0\n");
	}

	StackDestroy(&s);

	system("pause");
	return 0;
}