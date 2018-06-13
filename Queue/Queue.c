#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//��ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = (QueueNode*)malloc(sizeof(QueueNode));
	if (q->_head == NULL)
	{
		printf("��ʼ��ʧ��\n");
	}
	else
	{
		q->_head->_next = NULL;
	}
}

//����
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_head)
	{
		q->_tail = q->_head->_next;
		free(q->_head);
		q->_head = q->_tail;
	}
	printf("���ٳɹ�\n");
}

//���
void QueuePush(Queue* q, DataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("����ʧ��\n");
	}
	else
	{
		newnode->_data = x;
		newnode->_next = NULL;
		q->_tail->_next = newnode;
		q->_tail = newnode;
	}
}

//����
void QueuePop(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("�ö���Ϊ��\n");
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

//��ȡ��ͷԪ��
DataType QueueFront(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("�ö���Ϊ��\n");
		return -1;
	}
	else
	{
		return q->_head->_next->_data;
	}
}

//��ȡ��βԪ��
DataType QueueBack(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("�ö���Ϊ��\n");
		return -1;
	}
	else
	{
		return q->_tail->_data;
	}
}

//���г���
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

//�п�
int QueueEmpty(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return 1;
	}
	return 0;
}

//���
void QueuePrint(Queue* q)
{
	if (q->_head == q->_tail)
	{
		printf("�ö���Ϊ��\n");
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