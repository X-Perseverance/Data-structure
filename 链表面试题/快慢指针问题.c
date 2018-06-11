//����ָ������:
//���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
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

//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
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

//ɾ������ĵ�����K�����
void SListDelTailKNode(SListNode** plist, size_t k)
{
	SListNode* pos = SListFindTailKNode(*plist, k);
	SList_Erase(plist, pos);
}