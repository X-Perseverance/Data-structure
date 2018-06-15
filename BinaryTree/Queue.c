#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//��ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = (QueueNode*)malloc(sizeof(QueueNode));
	assert(q->_head&&q->_tail);
	q->_head->_next = NULL;
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
}

//���
void QueuePush(Queue* q, QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_next = NULL;
	q->_tail->_next = newnode;
	q->_tail = newnode;
}

//����
void QueuePop(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return;
	}
	QueueNode* next = q->_head->_next;
	q->_head->_next = next->_next;
	if (q->_tail == next)
	{
		q->_tail = q->_head;
	}
	free(next);
}

//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return NULL;
	}
	else
	{
		return q->_head->_next->_data;
	}
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