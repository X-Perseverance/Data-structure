//逆置/反转单链表
//方法一：
SListNode* SListReverse_1(SListNode* list)
{
	SListNode* cur = list;
	SListNode* newhead = NULL;
	while (cur)
	{
		SListNode* next = cur->_next;
		cur->_next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}

//方法二：
SListNode* SListReverse_2(SListNode* list)
{
	SListNode* n1 = list;
	SListNode* n2 = n1->_next;
	SListNode* n3 = n2->_next;
	while (n2)
	{
		n2->_next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->_next;
		}
	}
	list->_next = NULL;
	return n1;
}