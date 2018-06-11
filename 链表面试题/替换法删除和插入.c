#define _CRT_SECURE_NO_WARNINGS 1

//删除一个无头单链表的非尾节点（不能遍历链表）——替换法删除
void SListDelNonTailNode(SListNode* pos)
{
	assert(pos->_next);
	SListNode* next = pos->_next;
	pos->_data = next->_data;
	pos->_next = next->_next;
	free(next);
}

//在无头单链表的一个节点前插入一个节点（不能遍历链表）——替换法插入
void SListInsertFrontNode(SListNode* pos, DataType x)
{
	SListNode* newNode = Buy_SListNode(pos->_data);
	newNode->_next = pos->_next;
	pos->_next = newNode;
	pos->_data = x;
}