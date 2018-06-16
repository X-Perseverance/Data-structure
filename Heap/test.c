#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

int main()
{
	Heap hp;
	HeapDateType a[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	size_t size = sizeof(a) / sizeof(HeapDateType);

	HeapInit(&hp, a, size);
	HeapMake(&hp);
	printf("��ʼ���ѣ�");
	HeapPrint(&hp);

	if (!HeapEmpty(&hp))
	{
		printf("�ڵ�����%d\n", GetHeapSize(&hp));
	}

	printf("����100��");
	HeapPush(&hp, 100);
	HeapPrint(&hp);

	printf("ɾ����");
	HeapPop(&hp);
	HeapPrint(&hp);

	printf("�Ѷ���%d\n", HeapTop(&hp));

	printf("����");
	HeapSort(&hp);
	HeapPrint(&hp);

	HeapTopK(a, size, 3);

	system("pause");
	return 0;
}