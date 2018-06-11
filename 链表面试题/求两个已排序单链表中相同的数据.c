//求两个已排序单链表中相同的数据
void UnionSet(SListNode* list1, SListNode* list2)
{
	assert(list1&&list2);
	SListNode* cur1 = list1;
	SListNode* cur2 = list2;
	while (cur1 && cur2)
	{
		if (cur1->_data < cur2->_data)
		{
			cur1 = cur1->_next;
		}
		else if (cur1->_data > cur2->_data)
		{
			cur2 = cur2->_next;
		}
		else
		{
			printf("%d ", cur1->_data);
			cur1 = cur1->_next;
			cur2 = cur2->_next;
		}
	}
}