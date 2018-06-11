//判断单链表是否带环
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
			return slow; //快慢指针相遇点
		}
	}
	return NULL;
}