#define _CRT_SECURE_NO_WARNINGS 1

#include "Hash.h"

//��ʼ��
void HashTableInit(HashTable* ht, size_t Initsize)
{
	ht->_tables = (HashNode*)malloc(Initsize*sizeof(HashNode));
	assert(ht->_tables);
	ht->_size = 0;
	ht->_capacity = Initsize;
	for (size_t i = 0; i < ht->_capacity; i++)
	{
		ht->_tables[i]._status = EMPTY;
	}
}

//����
void HashTableDestory(HashTable* ht)
{
	assert(ht);
	free(ht->_tables);
	ht->_tables = NULL;
	ht->_size = ht->_capacity = 0;
}

//����λ��
size_t HashFunc(HashTable* ht, HashDataType data)
{
	return data % ht->_capacity;
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
	if (ht->_size * 10 / ht->_capacity > 7)
	{
		HashTable newht;
		HashTableInit(&newht, GetNextPrimeNum(ht));
		for (size_t i = 0; i < ht->_capacity; i++) //�Ѿɱ��е���Ч����ȫ�����뵽�±�
		{
			if (ht->_tables[i]._status == EXITS)
			{
				HashTableInsert(&newht, ht->_tables[i]._data);
			}
		}
		HashTableDestory(ht);
		ht->_tables = newht._tables;
		ht->_size = newht._size;
		ht->_capacity = newht._capacity;
	}
}

//����
int HashTableInsert(HashTable* ht, HashDataType data)
{
	assert(ht);
	Checkcapacity(ht);
	size_t start = HashFunc(ht, data);
	size_t index = start;
	size_t i = 1;
	while (ht->_tables[index]._status == EXITS)
	{
		if (ht->_tables[index]._data == data)
		{
			return 0;
		}

		////һ��̽��
		//index++;
		//if (index == ht->_capacity)
		//{
		//	index = 0;
		//}

		//����̽��
		index = (start + i*i) % (ht->_capacity);	
		i++;
	}
	ht->_tables[index]._data = data;
	ht->_tables[index]._status = EXITS;
	ht->_size++;
	return 1;
}

//����
HashNode* HashTableFind(HashTable* ht, HashDataType data)
{
	assert(ht);
	size_t start = HashFunc(ht, data);
	size_t index = start;
	size_t i = 1;
	while (ht->_tables[index]._status == EXITS)
	{
		if (ht->_tables[index]._data == data)
		{
			return &(ht->_tables[index]);
		}

		////һ��̽��
		//index++;
		//if (index == ht->_capacity)
		//{
		//	index = 0;
		//}

		//����̽��
		index = (start + i*i) % (ht->_capacity);
		i++;
	}
	return NULL;
}

//ɾ��
int HashTableRemove(HashTable* ht, HashDataType data)
{
	assert(ht);
	HashNode* del = HashTableFind(ht, data);
	if (del)
	{
		del->_status = DELETE;
		ht->_size--;
		return 1;
	}
	return 0;
}

//��ӡ
void HashTablePrint(HashTable* ht)
{
	assert(ht);
	for (size_t i = 0; i < ht->_capacity; i++)
	{
		if (ht->_tables[i]._status == EXITS)
		{
			printf("[EXITS��%d] ", ht->_tables[i]._data);
		}
		else if (ht->_tables[i]._status == DELETE)
		{
			printf("[DELETE��%d] ", ht->_tables[i]._data);
		}
		else
		{
			printf("[EMPTY] ");
		}
	}
	printf("\n");
}