#define _CRT_SECURE_NO_WARNINGS 1

#include "BSTree.h"

int main()
{
	BSTreeNode* tree = NULL;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		BSTreeInsertR(&tree, a[i]);
	}

	BSTreeInOrder(tree);
	printf("\n");

	const BSTreeNode* node = BSTreeFindR(tree, 2);
	if (node)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}

	BSTreeRemove(&tree, 2);
	BSTreeRemove(&tree, 5);
	BSTreeRemove(&tree, 7);
	BSTreeRemove(&tree, 9);

	BSTreeInOrder(tree);
	printf("\n");

	BSTreeDestory(tree);

	system("pause");
	return 0;
}