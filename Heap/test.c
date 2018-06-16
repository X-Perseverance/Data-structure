#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

int main()
{
	Heap hp;
	HeapDateType a[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	size_t size = sizeof(a) / sizeof(HeapDateType);

	HeapInit(&hp, a, size);
	HeapMake(&hp);
	printf("初始化堆：");
	HeapPrint(&hp);

	if (!HeapEmpty(&hp))
	{
		printf("节点数：%d\n", GetHeapSize(&hp));
	}

	printf("插入100：");
	HeapPush(&hp, 100);
	HeapPrint(&hp);

	printf("删除：");
	HeapPop(&hp);
	HeapPrint(&hp);

	printf("堆顶：%d\n", HeapTop(&hp));

	printf("升序：");
	HeapSort(&hp);
	HeapPrint(&hp);

	HeapTopK(a, size, 3);

	system("pause");
	return 0;
}