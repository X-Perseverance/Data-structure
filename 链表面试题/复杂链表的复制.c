//复杂链表复制:
//一个链表的每个节点，有一个next指针指向下一个节点，还有一个random指针指向这个链表中的一个随机节点
//或者NULL，现在要求实现复制这个链表，返回复制后的新链表。

typedef struct ComplexListNode
{
	int _data;
	struct ComplexListNode* _next;
	struct ComplexListNode* _random;
} ComplexListNode;

ComplexListNode* CopyComplexList(ComplexListNode * list)
{
	if (list == NULL)
	{
		return NULL;
	}

	//第一步：复制节点
	ComplexListNode * cur = list;
	while (cur)
	{
		ComplexListNode * newnode = Buy_SListNode(cur->_data);
		newnode->_next = cur->_next;
		cur->_next = newnode;
		newnode->_random = NULL;
		cur = cur->_next->_next;
	}

	//第二步：复制random指针
	cur = list;
	while (cur)
	{
		if (cur->_random)
		{
			cur->_next->_random = cur->_random->_next;
		}
		else
		{
			cur->_next->_random = NULL;
		}
		cur = cur->_next->_next;
	}

	//第三步：拆分，重新连接
	cur = list;
	ComplexListNode * newlist = list->_next;
	ComplexListNode * newcur = newlist;
	while (cur)
	{
		cur->_next = cur->_next->_next;
		if (newcur->_next)
		{
			newcur->_next = newcur->_next->_next;
		}
		else
		{
			newcur->_next = NULL;
		}
		cur = cur->_next;
		newcur = newcur->_next;
	}
	return newlist;
}