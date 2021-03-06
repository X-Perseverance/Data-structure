#define _CRT_SECURE_NO_WARNINGS 1

#include "BloomFilter.h"

//初始化
void BloomFilterInit(BloomFilter* bf, size_t range)
{
	assert(bf);
	BitMapInit(&(bf->_bm), range*5);
}

//字符串哈希算法
size_t BFHashFunc1(BFKeyType str)
{
	register size_t hash = 0;
	while (*str)
	{
		hash = hash * 131 + (*str++);
	}
	return hash;
}

size_t BFHashFunc2(BFKeyType str)
{
	register size_t hash = 0;
	size_t magic = 63689;
	while (*str)
	{
		hash = hash * magic + (*str++);
		magic *= 378551;
	}
	return hash;
}

size_t BFHashFunc3(BFKeyType str)
{
	register size_t hash = 0;
	while (*str)
	{
		hash = 65599 * hash + (*str++);
	}
	return hash;
}

//将x所在的位置置为1
void BloomFilterSet(BloomFilter* bf, BFKeyType key)
{
	assert(bf);
	size_t hash1 = BFHashFunc1(key) % bf->_bm._range;
	BitMapSet(&bf->_bm, hash1);

	size_t hash2 = BFHashFunc2(key) % bf->_bm._range;
	BitMapSet(&bf->_bm, hash2);

	size_t hash3 = BFHashFunc3(key) % bf->_bm._range;
	BitMapSet(&bf->_bm, hash3);
}

//检测x是否存在
int BloomFilterTest(BloomFilter* bf, BFKeyType key)
{
	assert(bf);
	size_t hash1 = BFHashFunc1(key) % bf->_bm._range;
	if (BitMapTest(&bf->_bm, hash1) == 0)
	{
		return 0;
	}

	size_t hash2 = BFHashFunc2(key) % bf->_bm._range;
	if (BitMapTest(&bf->_bm, hash2) == 0)
	{
		return 0;
	}

	size_t hash3 = BFHashFunc3(key) % bf->_bm._range;
	if (BitMapTest(&bf->_bm, hash3) == 0)
	{
		return 0;
	}
	return 1;
}

//销毁
void BloomFilterDestory(BloomFilter* bf)
{
	assert(bf);
	BitMapDestroy(&bf->_bm);
}