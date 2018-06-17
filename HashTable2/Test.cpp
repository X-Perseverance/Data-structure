#define _CRT_SECURE_NO_WARNINGS 1

#include "Hash.h"

int main()
{
    HashTable ht;
    HashTableInit(&ht, 5);
    int arr[] = { 10, 20, 30, 40, 50 };

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        HashTableInsert(&ht, arr[i]);
    }
    HashTablePrint(&ht);

    HashNode* cur = HashTableFind(&ht, 1);
    if (cur)
    {
        printf("找到：%d\n", cur->_key);
    }
    else
    {
        printf("未找到\n");
    }

    HashTableInsert(&ht, 1);
    HashTableInsert(&ht, 2);
    HashTableInsert(&ht, 3);
    HashTableInsert(&ht, 4);
    HashTablePrint(&ht);

    cur = HashTableFind(&ht, 1);
    if (cur)
    {
        printf("找到：%d\n", cur->_key);
    }
    else
    {
        printf("未找到\n");
    }

    HashTableRemove(&ht, 1);
    HashTablePrint(&ht);

    cur = HashTableFind(&ht, 1);
    if (cur)
    {
        printf("找到：%d\n", cur->_key);
    }
    else
    {
        printf("未找到\n");
    }

    HashTableDestory(&ht);

    system("pause");
    return 0;
}