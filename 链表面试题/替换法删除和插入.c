#define _CRT_SECURE_NO_WARNINGS 1

//ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ������������滻��ɾ��
void SListDelNonTailNode(SListNode* pos)
{
	assert(pos->_next);
	SListNode* next = pos->_next;
	pos->_data = next->_data;
	pos->_next = next->_next;
	free(next);
}

//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ������������滻������
void SListInsertFrontNode(SListNode* pos, DataType x)
{
	SListNode* newNode = Buy_SListNode(pos->_data);
	newNode->_next = pos->_next;
	pos->_next = newNode;
	pos->_data = x;
}