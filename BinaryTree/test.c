#define _CRT_SECURE_NO_WARNINGS 1

#include "BTree.h"

int main()
{
	//int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, '#', '#', '#' };
	int a[] = { 1, 2, 3, '#', '#', '#', 5, 6, '#', '#', '#' };
	size_t index = 0;

	BTNode* tree = CreateBTree(a, &index, '#');
	printf("先序遍历：");
	BTreePrevOrder(tree);
	printf("\n");

	printf("非递归先序遍历：");
	BTreePrevOrderNonR(tree);
	printf("\n");

	printf("中序遍历：");
	BTreeInOrder(tree);
	printf("\n"); 

	printf("非递归中序遍历：");
	BTreeInOrder(tree);
	printf("\n");

	printf("后序遍历：");
	BTreePostOrder(tree);
	printf("\n");

	printf("非递归后序遍历：");
	BTreePostOrder(tree);
	printf("\n");

	printf("层序遍历：");
	BTreeLevelOrder(tree);
	printf("\n");

	printf("总节点数：%d\n", BTreeSize(tree));
	printf("叶子节点数：%d\n", BTreeLeafSize(tree));
	printf("第%d层节点数：%d\n", 2, BTreeKLevelSize(tree, 2));
	printf("深度：%d\n", BTreeDepth(tree));
	printf("是否为完全二叉树？%d\n", IsCompleteBTree(tree));
	printf("是否为完全二叉树？%d\n", IsCompleteBTree1(tree));

	if (BTreeFind(tree, 4))
	{
		printf("找到了\n");
	}
	else
	{
		printf("未找到\n");
	}

	system("pause");
	return 0;
}