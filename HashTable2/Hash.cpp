#define _CRT_SECURE_NO_WARNINGS 1

#include "Hash.h"

//��ʼ��
void HashTableInit(HashTable* ht, size_t Initsize)
{
    assert(ht);
    ht->_tables = (HashNode**)malloc(Initsize*sizeof(HashNode*));
    assert(ht->_tables);
    ht->_size = 0;
    ht->_capacity = Initsize;
    for (size_t i = 0; i < ht->_capacity; i++)
    {
        ht->_tables[i] = NULL;
    }
}

//����
void HashTableDestory(HashTable* ht)
{
    assert(ht);
    for (size_t index = 0; index < ht->_capacity; index++) //������ÿһ������
    {
        HashNode* cur = ht->_tables[index];
        while (cur)
        {
            HashNode* next = cur->_next;
            free(cur);
            cur = NULL;
            cur = next;
        }
    }
    free(ht->_tables); //������˳���
    ht->_tables = NULL;
    ht->_size = ht->_capacity = 0;
}

//��ϣ����-����λ��
size_t HashFunc(HashTable* ht, KeyType key)
{
    return key % ht->_capacity;
}

//������
static size_t GetNextPrimeNum(HashTable* ht)
{
    const int _PrimeSize = 28;
    static const unsigned long _PrimeList[_PrimeSize] =
    {
        53ul, 97ul, 193ul, 389ul, 769ul,
        1543ul, 3079ul, 6151ul, 12289ul,
        24593ul, 49157ul, 98317ul, 196613ul,
        393241ul, 786433ul, 1572869ul, 3145739ul,
        6291469ul, 12582917ul, 25165843ul, 50331653ul,
        100663319ul, 201326611ul, 402653189ul, 805306457ul,
        1610612741ul, 3221225473ul, 4294967291ul
    };
    int index = 0;
    while (index < _PrimeSize)
    {
        if (ht->_capacity < _PrimeList[index])
        {
            return _PrimeList[index];
        }
        index++;
    }
    return _PrimeList[_PrimeSize - 1];
}

//����
void Checkcapacity(HashTable* ht)
{
    assert(ht);
    if (ht->_size == ht->_capacity) //���غ����ӿ�����1
    {
        HashTable newht; //�½�һ����ϣ��
        HashTableInit(&newht, GetNextPrimeNum(ht));
        for (size_t i = 0; i < ht->_capacity; i++)
        {
            HashNode* cur = ht->_tables[i];
            while (cur)
            {
                HashNode* next = cur->_next; //������һ���ڵ�
                size_t index = HashFunc(&newht, cur->_key); //���¼���ԭ��ϣ����ÿһ��key���¹�ϣ���е�λ��
                 //����ԭ���ѿ��ٵĿռ����������ӣ����������¿��ٿռ�
                cur->_next = newht._tables[index];      
                newht._tables[index] = cur;
                cur = next;
            }
            ht->_tables[i] = NULL;
        }
        free(ht->_tables); //����ԭ��ϣ��
        ht->_tables = newht._tables; //���¹�ϣ��
        ht->_capacity = newht._capacity;
    }
}

//�������
HashNode* BuyHashNode(KeyType key)
{
    HashNode* newnode = (HashNode*)malloc(sizeof(HashNode));
    assert(newnode);
    newnode->_key = key;
    newnode->_next = NULL;
    return newnode;
}

//����
int HashTableInsert(HashTable* ht, KeyType key)
{
    assert(ht);
    Checkcapacity(ht);
    size_t index = HashFunc(ht, key);
    HashNode* cur = ht->_tables[index];
    while (cur)
    {
        if (cur->_key == key)
        {
            return 0;
        }
        cur = cur->_next;
    }
    HashNode* newnode = BuyHashNode(key);
    newnode->_next = ht->_tables[index];
    ht->_tables[index] = newnode;
    ht->_size++;
    return 1;
}

//����
HashNode* HashTableFind(HashTable* ht, KeyType key)
{
    assert(ht);
    size_t index = HashFunc(ht, key);
    HashNode* cur = ht->_tables[index];
    while (cur)
    {
        if (cur->_key == key)
        {
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}

//ɾ��
int HashTableRemove(HashTable* ht, KeyType key)
{
    assert(ht);
    size_t index = HashFunc(ht, key);
    HashNode* cur = ht->_tables[index];
    if (cur == NULL)
    {
        return 0;
    }
    else if (cur->_next == NULL)
    {
        if (cur->_key == key)
        {
            free(cur);
            ht->_tables[index] = NULL;
            ht->_size--;
            return 1;
        }
        return 0;
    }
    else
    {
        HashNode* prev = ht->_tables[index];
        while (cur)
        {
            if (cur->_key == key)
            {
                prev->_next = cur->_next;
                free(cur);
                cur = NULL;
                ht->_size--;
                return 1;
            }
            prev = cur;
            cur = cur->_next;
        }
        return 0;
    }   
}

//��ӡ
void HashTablePrint(HashTable* ht)
{
    assert(ht);
    printf("\n");
    for (size_t index = 0; index < ht->_capacity; index++)
    {
        HashNode* cur = ht->_tables[index];
        while (cur)
        {
            printf("%d->", cur->_key);
            cur = cur->_next;
        }
        printf("NULL\n");
    }
    printf("\n");
}