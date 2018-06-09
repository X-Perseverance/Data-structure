#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//初始化
void SeqList_Init(SeqList *pSeq)
{
	assert(pSeq);
	memset(pSeq, 0, N*sizeof(DataType));
	pSeq->size = 0;
	printf("初始化成功\n");
}

//交换
void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//插入
void SeqList_Insert(SeqList *pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	if (pSeq->size == N)
	{
		printf("该顺序表已满\n");
	}
	else
	{
		assert(pos <= pSeq->size);
		for (int i = pSeq->size; i > (int)pos; i--)
		{
			pSeq->a[i] = pSeq->a[i - 1];
		}
		pSeq->a[pos] = x;
		pSeq->size++;
		printf("插入成功\n");
	}
}

//删除
void SeqList_Delete(SeqList *pSeq, size_t pos)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
	}
	else
	{
		assert(pos < pSeq->size);
		for (int i = pos + 1; i < (int)pSeq->size; i++)
		{
			pSeq->a[i - 1] = pSeq->a[i];
		}
		pSeq->size--;
		printf("删除成功\n");
	}
}

//删除顺序表中第一个出现的指定元素
void SeqList_Remove(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	int i = 0;
	int j = 0;
	for (i = 0; i < (int)pSeq->size; i++)
	{
		if (pSeq->a[i] == x)
		{
			for (j = i + 1; j < (int)pSeq->size; j++)
			{
				pSeq->a[j - 1] = pSeq->a[j];
			}
			pSeq->size--;
			printf("删除成功\n");
			return;
		}
	}
	if (i == (int)pSeq->size)
	{
		printf("该顺序表没有此值\n");
	}
}

//删除顺序表中所有指定的元素
void SeqList_RemoveAll(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	int p = 0;
	int q = 0;
	int count = 0;
	for (p = 0; p < (int)pSeq->size;)
	{
		if (pSeq->a[p] == x)
		{
			p++;
			count++;
		}
		else
		{
			pSeq->a[q++] = pSeq->a[p++];
		}
	}
	pSeq->size -= count;
	printf("删除成功\n");
}

//查找
void SeqList_Search(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	for (int i = 0; i < (int)pSeq->size; i++)
	{
		if (pSeq->a[i] == x)
		{
			printf("找到了，下标为%d\n", i);
			return;
		}
	}
	printf("未找到\n");
}

//修改
void SeqList_Modify(SeqList *pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	assert(pos < pSeq->size);
	pSeq->a[pos] = x;
	printf("修改成功\n");
}

//输出
void SeqList_Print(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	for (int i = 0; i < (int)pSeq->size; i++)
	{
		printf("%d ", pSeq->a[i]);
	}
	printf("\n");
}

//冒泡排序
void Bubble_Sort(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	for (int i = 0; i < (int)pSeq->size - 1; i++)
	{
		int j = 0;
		int flag = 0;
		for (; j < (int)pSeq->size - i - 1; j++)
		{
			if (pSeq->a[j] > pSeq->a[j + 1])
			{
				flag = 1;
				Swap(&pSeq->a[j], &pSeq->a[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	printf("排序成功\n");
}

//选择排序
void Select_Sort(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	int left = 0;
	int right = pSeq->size - 1;
	while (left < right)
	{
		int i = 0;
		int min = left;
		int max = left;
		for (i = left; i <= right; i++)
		{
			if (pSeq->a[i] < pSeq->a[min])
			{
				min = i;
			}
			if (pSeq->a[i] > pSeq->a[max])
			{
				max = i;
			}
		}
		if (min != left)
		{
			Swap(&pSeq->a[min], &pSeq->a[left]);
		}
		if (max == left) //若max和left相等，则经过上一步交换，导致原max处为最小值，而min处为最大值
		{
			max = min; //更新max,让其位置为最大值
		}
		if (max != right)
		{
			Swap(&pSeq->a[max], &pSeq->a[right]);
		}
		left++;
		right--;
	}
	printf("排序成功\n");
}

//二分查找
void Binary_Search(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("该顺序表为空\n");
		return;
	}
	int left = 0;
	int right = pSeq->size - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (pSeq->a[mid] > x)
		{
			right = mid - 1;
		}
		else if (pSeq->a[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标为%d\n", mid);
			return;
		}
	}
	printf("未找到\n");
}
