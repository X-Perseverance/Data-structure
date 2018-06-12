//方法一：非递归
void SLitsPrintTailToHead(SListNode* pHead)
{
	assert(pHead);
	SListNode* end = NULL;
	while (end != pHead)
	{
		SListNode* cur = pHead;
		while (cur->_next != end)
		{
			cur = cur->_next;
		}
		printf("%d ", cur->_data);
		end = cur;
	}
	printf("\n");
}


//方法二：递归
void SLitsPrintTailToHeadR(SListNode* pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	SLitsPrintTailToHeadR(pHead->_next);
	printf("%d ", pHead->_data);
}
