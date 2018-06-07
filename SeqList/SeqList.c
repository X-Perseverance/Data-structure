#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//��ʼ��
void SeqList_Init(SeqList *pSeq)
{
	assert(pSeq);
	memset(pSeq, 0, N*sizeof(DataType));
	pSeq->size = 0;
	printf("��ʼ���ɹ�\n");
}

//����
void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//����
void SeqList_Insert(SeqList *pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	if (pSeq->size == N)
	{
		printf("��˳�������\n");
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
		printf("����ɹ�\n");
	}
}

//ɾ��
void SeqList_Delete(SeqList *pSeq, size_t pos)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		assert(pos < pSeq->size);
		for (int i = pos + 1; i < (int)pSeq->size; i++)
		{
			pSeq->a[i - 1] = pSeq->a[i];
		}
		pSeq->size--;
		printf("ɾ���ɹ�\n");
	}
}

//ɾ��˳����е�һ�����ֵ�ָ��Ԫ��
void SeqList_Remove(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
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
			printf("ɾ���ɹ�\n");
			return;
		}
	}
	if (i == (int)pSeq->size)
	{
		printf("��˳���û�д�ֵ\n");
	}
}

//ɾ��˳���������ָ����Ԫ��
void SeqList_RemoveAll(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
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
	printf("ɾ���ɹ�\n");
}

//����
void SeqList_Search(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
		return;
	}
	for (int i = 0; i < (int)pSeq->size; i++)
	{
		if (pSeq->a[i] == x)
		{
			printf("�ҵ��ˣ��±�Ϊ%d\n", i);
			return;
		}
	}
	printf("δ�ҵ�\n");
}

//�޸�
void SeqList_Modify(SeqList *pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
		return;
	}
	assert(pos < pSeq->size);
	pSeq->a[pos] = x;
	printf("�޸ĳɹ�\n");
}

//���
void SeqList_Print(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
		return;
	}
	for (int i = 0; i < (int)pSeq->size; i++)
	{
		printf("%d ", pSeq->a[i]);
	}
	printf("\n");
}

//ð������
void Bubble_Sort(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
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
	printf("����ɹ�\n");
}

//ѡ������
void Select_Sort(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
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
		if (max == left)
		{
			max = min;
		}
		if (max != right)
		{
			Swap(&pSeq->a[max], &pSeq->a[right]);
		}
		left++;
		right--;
	}
	printf("����ɹ�\n");
}

//���ֲ���
void Binary_Search(SeqList *pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("��˳���Ϊ��\n");
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
			printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
			return;
		}
	}
	printf("δ�ҵ�\n");
}