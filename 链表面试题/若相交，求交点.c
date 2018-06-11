//若相交，求交点（都不带环）
SListNode* SListCrossNode_1(SListNode* list1, SListNode* list2)
{
	assert(list1&&list2);
	SListNode* tail = list1;
	SListNode* meet = NULL;
	while (tail->_next)
	{
		tail = tail->_next;
	}
	tail->_next = list2;
	meet = SListIsCycle(list1);
	return SListEntryNode(list1, meet);
}

//若相交，求交点（1.都不带环；2.环外相交）
SListNode* SListCrossNode_2(SListNode* list1, SListNode* list2)
{
	SListNode* longlist = NULL;
	SListNode* shortlist = NULL;
	SListNode* cur1 = list1;
	SListNode* cur2 = list2;
	int count1 = 0;
	int count2 = 0;
	int gap = 0;
	SListNode* meetNode = SListIsCycle(list1);
	//若都不带环，meetNode为NULL；若都带环，meetNode为环内一个节点
	while (cur1 != meetNode)
	{
		count1++;
		cur1 = cur1->_next;
	}
	while (cur2 != meetNode)
	{
		count2++;
		cur2 = cur2->_next;
	}
	longlist = list1;
	shortlist = list2;
	if (count1 < count2)
	{
		longlist = list2;
		shortlist = list1;
	}
	gap = abs(count1 - count2);
	while (gap--)
	{
		longlist = longlist->_next;
	}
	while (shortlist != longlist)
	{
		shortlist = shortlist->_next;
		longlist = longlist->_next;
	}
	return shortlist;
}

//若相交，求交点（环内相交）
void SListCrossNode_3(SListNode* list1, SListNode* list2)
{
	SListNode* meetNode1 = SListIsCycle(list1);
	printf("交点1是：%d\n", SListEntryNode(list1, meetNode1)->_data);
	SListNode* meetNode2 = SListIsCycle(list2);
	printf("交点2是：%d\n", SListEntryNode(list2, meetNode2)->_data);
}