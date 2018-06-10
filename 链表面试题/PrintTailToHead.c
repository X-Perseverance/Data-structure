#define _CRT_SECURE_NO_WARNINGS 1

//����һ���ǵݹ�
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

//���������ݹ�
void SLitsPrintTailToHeadR(SListNode* pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	SLitsPrintTailToHeadR(pHead->_next);
	printf("%d ", pHead->_data);
}