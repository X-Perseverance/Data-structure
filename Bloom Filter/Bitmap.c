#define _CRT_SECURE_NO_WARNINGS 1

#include "Bitmap.h"

//��ʼ��
void BitMapInit(BitMap* bm, size_t range)
{
	assert(bm);
	bm->_range = range;
	bm->_bits = (size_t*)malloc(sizeof(size_t)*((range >> 5) + 1));
	assert(bm->_bits);
	memset(bm->_bits, 0, sizeof(size_t)*((range >> 5) + 1));
}

//��x���ڵ�λ����Ϊ1
void BitMapSet(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 5;
	size_t num = x % 32;
	bm->_bits[index] |= (1 << num);
}

//��x���ڵ�λ����Ϊ0
void BitMapReset(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 5;
	size_t num = x % 32;
	bm->_bits[index] &= ~(1 << num);
}

//���x�Ƿ����
int BitMapTest(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 5;
	size_t num = x % 32;
	return ((bm->_bits[index] & (1 << num)) == 0) ? 0 : 1;
}

//����
void BitMapDestroy(BitMap* bm)
{
	assert(bm);
	free(bm->_bits);
	bm->_bits = NULL;
	bm->_range = 0;
}