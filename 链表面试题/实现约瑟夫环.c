//������ʵ��Լɪ��(JosephCircle)
SListNode* SListJosephCircle(SListNode* pHead, int k)
{
	SListNode* cur = pHead;
	SListNode* tail = pHead;
	while (tail->_next)
	{
		tail = tail->_next;
	}
	tail->_next = pHead; //���ɻ�

	while (cur->_next != cur)
	{
		int count = k;
		while (--count)
		{
			cur = cur->_next;
		}
		SListNode* next = cur->_next; //�滻��ɾ��
		cur->_data = next->_data;
		cur->_next = next->_next;
		free(next);
	}
	return cur;
}