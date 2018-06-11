//µ¥Á´±íÅÅÐò£¨Ã°ÅÝÅÅÐò)
void SListBubbleSort(SListNode* list)
{
	if (list == NULL)
	{
		return;
	}
	SListNode* tail = NULL;
	while ((list->_next) != tail)
	{
		int flag = 0;
		SListNode* cur = list;
		SListNode* next = cur->_next;
		while (next != tail)
		{
			if (cur->_data > next->_data)
			{
				flag = 1;
				DataType tmp = cur->_data;
				cur->_data = next->_data;
				next->_data = tmp;
			}
			cur = cur->_next;
			next = next->_next;
		}
		if (flag == 0)
		{
			break;
		}
		tail = cur;
	}
}