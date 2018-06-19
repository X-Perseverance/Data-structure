#define _CRT_SECURE_NO_WARNINGS 1

#include "BloomFilter.h"

int main()
{
	BloomFilter bf;
	BloomFilterInit(&bf, 10);

	BloomFilterSet(&bf, "a");
	BloomFilterSet(&bf, "ab");
	BloomFilterSet(&bf, "abc");

	printf("%d\n", BloomFilterTest(&bf, "a"));
	printf("%d\n", BloomFilterTest(&bf, "ab"));
	printf("%d\n", BloomFilterTest(&bf, "abc"));
	printf("%d\n", BloomFilterTest(&bf, "abcd"));

	BloomFilterDestory(&bf);

	system("pause");
	return 0;
}