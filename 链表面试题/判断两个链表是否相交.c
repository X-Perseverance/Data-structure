//判断两个链表是否相交
int SListIsCrossNode(SListNode* list1, SListNode* list2)
{
	assert(list1&&list2);
	SListNode* meet1 = SListIsCycle(list1);
	SListNode* meet2 = SListIsCycle(list2);

	//一：都不带环
	//判断两个链表最后一个结点是否相等
	if (meet1 == NULL&&meet2 == NULL)
	{
		SListNode* cur1 = list1;
		SListNode* cur2 = list2;
		while (cur1&&cur1->_next)
		{
			cur1 = cur1->_next;
		}
		while (cur2&&cur2->_next)
		{
			cur2 = cur2->_next;
		}
		if (cur1 == cur2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//二：都带环
	//判断两个相遇点是否在同一个环内
	else if (meet1 != NULL&&meet2 != NULL)
	{
		SListNode* cur = meet1;
		while (cur->_next != meet1)
		{
			if (cur == meet2)
			{
				return 1;
			}
			cur = cur->_next;
		}
		if (cur == meet2)
		{
			return 1;
		}
		return 0;
	}

	//三：一个带环，另一个不带环
	//肯定不相交
	else
	{
		return 0;
	}
}