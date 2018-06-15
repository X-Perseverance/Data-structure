#define _CRT_SECURE_NO_WARNINGS 1

#include "BTree.h"

int main()
{
	//int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, '#', '#', '#' };
	int a[] = { 1, 2, 3, '#', '#', '#', 5, 6, '#', '#', '#' };
	size_t index = 0;

	BTNode* tree = CreateBTree(a, &index, '#');
	printf("���������");
	BTreePrevOrder(tree);
	printf("\n");

	printf("�ǵݹ����������");
	BTreePrevOrderNonR(tree);
	printf("\n");

	printf("���������");
	BTreeInOrder(tree);
	printf("\n"); 

	printf("�ǵݹ����������");
	BTreeInOrder(tree);
	printf("\n");

	printf("���������");
	BTreePostOrder(tree);
	printf("\n");

	printf("�ǵݹ���������");
	BTreePostOrder(tree);
	printf("\n");

	printf("���������");
	BTreeLevelOrder(tree);
	printf("\n");

	printf("�ܽڵ�����%d\n", BTreeSize(tree));
	printf("Ҷ�ӽڵ�����%d\n", BTreeLeafSize(tree));
	printf("��%d��ڵ�����%d\n", 2, BTreeKLevelSize(tree, 2));
	printf("��ȣ�%d\n", BTreeDepth(tree));
	printf("�Ƿ�Ϊ��ȫ��������%d\n", IsCompleteBTree(tree));
	printf("�Ƿ�Ϊ��ȫ��������%d\n", IsCompleteBTree1(tree));

	if (BTreeFind(tree, 4))
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("δ�ҵ�\n");
	}

	system("pause");
	return 0;
}