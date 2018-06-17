#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int KeyType;

typedef struct HashNode
{
    KeyType _key;
    struct HashNode* _next;
}HashNode;

typedef struct HashTable
{
    HashNode** _tables; //????
    size_t _size;
    size_t _capacity;
}HashTable;

HashNode* BuyHashNode(KeyType key);
size_t HashFunc(HashTable* ht, KeyType key);
static size_t GetNextPrimeNum(HashTable* ht);

void HashTableInit(HashTable* ht, size_t Initsize);
int HashTableInsert(HashTable* ht, KeyType key);
HashNode* HashTableFind(HashTable* ht, KeyType key);
int HashTableRemove(HashTable* ht, KeyType key);
void HashTablePrint(HashTable* ht);
void HashTableDestory(HashTable* ht);

#endif __HASH_H__