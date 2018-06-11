//�ж����������Ƿ��ཻ
int SListIsCrossNode(SListNode* list1, SListNode* list2)
{
	assert(list1&&list2);
	SListNode* meet1 = SListIsCycle(list1);
	SListNode* meet2 = SListIsCycle(list2);

	//һ����������
	//�ж������������һ������Ƿ����
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

	//����������
	//�ж������������Ƿ���ͬһ������
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

	//����һ����������һ��������
	//�϶����ཻ
	else
	{
		return 0;
	}
}