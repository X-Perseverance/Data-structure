#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = (QueueNode*)malloc(sizeof(QueueNode));
	if (q->_head == NULL)
	{
		printf("初始化失败\n");
	}
	else
	{
		q->_head->_next = NULL;
	}
}

//销毁
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_head)
	{
		q->_tail = q->_head->_next;
		free(q->_head);
		q->_head = q->_tail;
	}
	printf("销毁成功\n");
}

//入队
void QueuePush(Queue* q, DataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("插入失败\n");
	}
	else
	{
		newnode->_data = x;
		newnode->_next = NULL;
		q->_tail->_next = newnode;
		q->_tail = newnode;
	}
}

//出队
void QueuePop(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("该队列为空\n");
	}
	else
	{
		QueueNode* next = q->_head->_next;
		q->_head->_next = next->_next;
		if (q->_tail == next)
		{
			q->_tail = q->_head;
		}
		free(next);
	}
}

//获取队头元素
DataType QueueFront(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("该队列为空\n");
		return -1;
	}
	else
	{
		return q->_head->_next->_data;
	}
}

//获取队尾元素
DataType QueueBack(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("该队列为空\n");
		return -1;
	}
	else
	{
		return q->_tail->_data;
	}
}

//队列长度
size_t QueueSize(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_head->_next;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

//判空
int QueueEmpty(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return 1;
	}
	return 0;
}

//输出
void QueuePrint(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("该队列为空\n");
	}
	else
	{
		QueueNode* cur = q->_head->_next;
		while(cur)
		{
			printf("%d ", cur->_data);
			cur = cur->_next;
		}
		printf("\n");
	}
}