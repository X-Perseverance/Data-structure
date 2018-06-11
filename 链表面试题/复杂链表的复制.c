//����������:
//һ�������ÿ���ڵ㣬��һ��nextָ��ָ����һ���ڵ㣬����һ��randomָ��ָ����������е�һ������ڵ�
//����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������

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

	//��һ�������ƽڵ�
	ComplexListNode * cur = list;
	while (cur)
	{
		ComplexListNode * newnode = Buy_SListNode(cur->_data);
		newnode->_next = cur->_next;
		cur->_next = newnode;
		newnode->_random = NULL;
		cur = cur->_next->_next;
	}

	//�ڶ���������randomָ��
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

	//����������֣���������
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