#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h" 

//�������
DListNode* BuyDListNode(DataType x)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}

//��ʼ��
DListNode* DListInit()
{
	DListNode* list = BuyDListNode(0);
	list->_next = list;
	list->_prev = list;
	return list;
}

//����
void DListDestroy(DListNode* head)
{
	DListNode* cur = head->_next;
	while (cur!=head)
	{
		DListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(head);
}

//���
void DListPrint(DListNode* head)
{
	DListNode* cur = head->_next;
	while (cur != head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("head\n");
}

//β��
void DListPushBack(DListNode* head, DataType x)
{
	assert(head);
	DListNode* tail = head->_prev;
	DListNode* newnode = BuyDListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;

	//DListInsert(head, x);
}

//ͷ��
void DListPushFront(DListNode* head, DataType x)
{
	assert(head);
	DListNode* first = head->_next;
	DListNode* newnode = BuyDListNode(x);	
	head->_next = newnode;
	newnode->_prev = head; 
	newnode->_next = first;
	first->_prev = newnode;

	//DListInsert(head->_next, x);
}

//βɾ
void DListPopBack(DListNode* head)
{
	assert(head);
	if (head->_next == NULL)
	{
		printf("������Ϊ��\n");
		return;
	}
	DListNode* tail = head->_prev;
	DListNode* prev = tail->_prev;
	prev->_next = head;
	head->_prev = prev;
	free(tail);

	//DListErase(head->_prev);
}

//ͷɾ
void DListPopFront(DListNode* head)
{
	assert(head);
	if (head->_next == NULL)
	{
		printf("������Ϊ��\n");
		return;
	}
	DListNode* first = head->_next;
	DListNode* next = first->_next;
	head->_next = next;
	next->_prev = head;
	free(first);

	//DListErase(head->_next);
}

//����
DListNode* DListFind(DListNode* head, DataType x)
{
	DListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//����
void DListInsert(DListNode* pos, DataType x)
{
	assert(pos);
	DListNode* prev = pos->_prev;
	DListNode* newnode = BuyDListNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

//ɾ��
void DListErase(DListNode* pos)
{
	assert(pos);
	DListNode* prev = pos->_prev;
	DListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}