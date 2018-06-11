//快慢指针问题:
//查找单链表的中间节点，要求只能遍历一次链表 
SListNode* SListFindMidNode(SListNode* list)
{
	if (list == NULL || list->_next == NULL)
	{
		return list;
	}
	else
	{
		SListNode* slow = list;
		SListNode* fast = list->_next->_next;
		while (fast)
		{
			slow = slow->_next;
			fast = fast->_next;
			if (fast)
			{
				fast = fast->_next;
			}
		}
		return slow;
	}
}

//查找单链表的倒数第k个节点，要求只能遍历一次链表 
SListNode* SListFindTailKNode(SListNode* list, size_t k)
{
	SListNode* slow = list;
	SListNode* fast = list;
	while (k--)
	{
		if (fast)
			fast = fast->_next;
		else
			return NULL;
	}
	while (fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	return slow;
}

//删除链表的倒数第K个结点
void SListDelTailKNode(SListNode** plist, size_t k)
{
	SListNode* pos = SListFindTailKNode(*plist, k);
	SList_Erase(plist, pos);
}