//�жϵ������Ƿ����
SListNode* SListIsCycle(SListNode* list)
{
	SListNode* slow = list;
	SListNode* fast = list;
	while (fast&&fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (fast == slow)
		{
			return slow; //����ָ��������
		}
	}
	return NULL;
}