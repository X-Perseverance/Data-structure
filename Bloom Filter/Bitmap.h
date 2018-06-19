#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct BitMap
{
	size_t* _bits;
	size_t _range;
}BitMap;

void BitMapInit(BitMap* bm, size_t range);
void BitMapSet(BitMap* bm, size_t x);
void BitMapReset(BitMap* bm, size_t x);
int BitMapTest(BitMap* bm, size_t x);
void BitMapDestroy(BitMap* bm);

#endif __BITMAP_H__