#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

int main()
{ 
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);

	QueuePrint(&q);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);

	QueuePrint(&q);

	printf("��ͷ��%d\n", QueueFront(&q));
	printf("��β��%d\n", QueueBack(&q));

	if (!QueueEmpty(&q))
	{
		printf("���ȣ�%d\n", QueueSize(&q));
	}
	else
	{
		printf("���ȣ�0\n");
	}

	QueueDestroy(&q);

	system("pause");
	return 0;
}