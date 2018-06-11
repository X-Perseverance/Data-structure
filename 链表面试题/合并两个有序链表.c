//合并两个有序链表,合并后依然有序 
SListNode* SListMerge(SListNode* list1, SListNode* list2)
{
	assert(list1&&list2);
	SListNode* list = NULL;
	SListNode* tail = NULL;
	if (list1->_data < list2->_data)
	{
		list = tail = list1;
		list1 = list1->_next;
	}
	else
	{
		list = tail = list2;
		list2 = list2->_next;
	}
	while (list1&&list2)
	{
		if (list1->_data < list2->_data)
		{
			tail->_next = list1;
			list1 = list1->_next;
		}
		else
		{
			tail->_next = list2;
			list2 = list2->_next;
		}
		tail = tail->_next;
	}
	if (list1)
	{
		tail->_next = list1;
	}
	if (list2)
	{
		tail->_next = list2;
	}
	return list;
}