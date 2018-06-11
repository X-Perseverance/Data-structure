//若带环，求环的长度
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

//求环的入口点
//方法：L = k*C - X
//L是链表起点到环入口点的长度；k是系数；C是环长度；X是入口点到快慢指针相遇点的长度。
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