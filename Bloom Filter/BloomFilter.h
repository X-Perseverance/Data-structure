#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__

#include "Bitmap.h"

typedef const char* BFKeyType;

typedef struct BloomFilter
{
	BitMap _bm;
}BloomFilter;

void BloomFilterInit(BloomFilter* bf, size_t range);
void BloomFilterSet(BloomFilter* bf, BFKeyType key);
int BloomFilterTest(BloomFilter* bf, BFKeyType key);
void BloomFilterDestory(BloomFilter* bf);

#endif __BLOOMFILTER_H__