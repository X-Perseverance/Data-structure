#define _CRT_SECURE_NO_WARNINGS 1

#include "Bitmap.h"

int main()
{
	BitMap bm;
	BitMapInit(&bm, 10);

	BitMapSet(&bm, 1);
	BitMapSet(&bm, 3);
	BitMapSet(&bm, 5);

	printf("%d\n", BitMapTest(&bm, 1));
	printf("%d\n", BitMapTest(&bm, 3));
	printf("%d\n", BitMapTest(&bm, 5));
	printf("%d\n", BitMapTest(&bm, 7));

	BitMapReset(&bm, 1);
	BitMapReset(&bm, 3);
	BitMapReset(&bm, 5);
	BitMapReset(&bm, 7);

	printf("%d\n", BitMapTest(&bm, 1));
	printf("%d\n", BitMapTest(&bm, 3));
	printf("%d\n", BitMapTest(&bm, 5));
	printf("%d\n", BitMapTest(&bm, 7));

	BitMapDestroy(&bm);

	system("pause");
	return 0;
}