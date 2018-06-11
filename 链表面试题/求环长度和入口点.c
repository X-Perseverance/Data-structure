//���������󻷵ĳ���
int SListCycleLen(SListNode* meetNode)
{
	SListNode* cur = meetNode;
	int count = 1;
	while ((cur->_next) != meetNode)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

//�󻷵���ڵ�
//������L = k*C - X
//L��������㵽����ڵ�ĳ��ȣ�k��ϵ����C�ǻ����ȣ�X����ڵ㵽����ָ��������ĳ��ȡ�
SListNode* SListEntryNode(SListNode* list, SListNode* meetNode)
{
	SListNode* cur1 = list;
	SListNode* cur2 = meetNode;
	while (cur1 != cur2)
	{
		cur1 = cur1->_next;
		cur2 = cur2->_next;
	}
	return cur1;
}