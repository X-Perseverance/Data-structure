#define _CRT_SECURE_NO_WARNINGS 1

#include "Hash.h"

int main()
{
	HashTable ht;
	HashTableInit(&ht, 5);
	int arr[] = { 10, 20, 20, 30, 40, 50 };

	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		HashTableInsert(&ht, arr[i]);
	}
	HashTablePrint(&ht);

	HashNode* cur = HashTableFind(&ht, 30);
	if (cur)
	{
		printf("%d\n", cur->_data);
	}
	else
	{
		printf("NULL\n");
	}

	HashTableRemove(&ht, 30);
	HashTablePrint(&ht);

	cur = HashTableFind(&ht, 30);
	if (cur)
	{
		printf("%d\n", cur->_data);
	}
	else
	{
		printf("NULL\n");
	}

	HashTableDestory(&ht);

	system("pause");
	return 0;
}