#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HashDataType;

typedef enum Status
{
	EMPTY,
	EXITS,
	DELETE,
}Status;

typedef struct HashNode
{
	HashDataType _data;
	Status _status;
}HashNode;

typedef struct HashTable
{
	HashNode* _tables;
	size_t _size;
	size_t _capacity;
}HashTable;

void HashTableInit(HashTable* ht, size_t Initsize);
int HashTableInsert(HashTable* ht, HashDataType data);
HashNode* HashTableFind(HashTable* ht, HashDataType data);
int HashTableRemove(HashTable* ht, HashDataType data);
void HashTablePrint(HashTable* ht);
void HashTableDestory(HashTable* ht);

#endif __HASH_H__