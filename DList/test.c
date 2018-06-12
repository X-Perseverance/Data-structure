#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

int main()
{
	DListNode* list = DListInit();
	DListPushBack(list, 1);
	DListPushBack(list, 2);
	DListPushBack(list, 3);
	DListPushBack(list, 4);
	DListPushBack(list, 5);
	DListPrint(list);

	DListPushFront(list, -1);
	DListPushFront(list, -2);
	DListPushFront(list, -3);
	DListPrint(list);

	DListPopFront(list);
	DListPopFront(list);
	DListPrint(list);

	DListPopBack(list);
	DListPopBack(list); 
	DListPrint(list);

	system("pause");
	return 0;
}