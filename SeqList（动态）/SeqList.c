#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//��ʼ��
void SeqInit(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->_size = 0;
	pSeq->_capacity = 5;
	pSeq->_a = (DataType *)malloc(pSeq->_capacity * sizeof(DataType));
	if (pSeq->_a == NULL)
	{
		perror("SeqInit");
		return;
	}
	memset(pSeq->_a, 0, pSeq->_capacity * sizeof(DataType));
	printf("��ʼ���ɹ�\n");
}

//����
void CheckCapacity(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->_size >= pSeq->_capacity)
	{
		DataType* ptr = (DataType *)realloc(pSeq->_a, (pSeq->_capacity + 2) * sizeof(DataType));
		if (ptr == NULL)
		{
			perror("CheckCapacity");
		}
		else
		{
			pSeq->_a = ptr;
			pSeq->_capacity += 2;
		}
	}
}

//���
void SeqPrint(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		for (int i = 0; i < (int)pSeq->_size; i++)
		{
			printf("%d ", pSeq->_a[i]);
		}
		printf("\n");
	}
}

//����
void SeqDestroy(SeqList* pSeq)
{
	assert(pSeq);
	free(pSeq->_a);
	pSeq->_a = NULL;
	pSeq->_capacity = 0;
	pSeq->_size = 0;
	printf("���ٳɹ�\n");
}

//β��
void SeqPushBack(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	CheckCapacity(pSeq);
	pSeq->_a[pSeq->_size] = x;
	pSeq->_size++;
}

//ͷ��
void SeqPushFront(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	CheckCapacity(pSeq);
	for (int i = pSeq->_size; i > 0; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];
	}
	pSeq->_a[0] = x;
	pSeq->_size++;
}

//βɾ
void SeqPopBack(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		pSeq->_size--;
		printf("ɾ���ɹ�\n");
	}
}

//ͷɾ
void SeqPopFront(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		for (int i = 1; i < (int)pSeq->_size; i++)
		{
			pSeq->_a[i - 1] = pSeq->_a[i];
		}
		pSeq->_size--;
		printf("ɾ���ɹ�\n");
	}
}

//����
void SeqInsert(SeqList* pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	assert(pos <= pSeq->_size);
	CheckCapacity(pSeq);
	for (int i = (int)pSeq->_size; i > (int)pos; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];
	}
	pSeq->_a[pos] = x;
	pSeq->_size++;
}

//ɾ��
void SeqErase(SeqList* pSeq, size_t pos)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		assert(pos < pSeq->_size);
		for (int i = pos + 1; i < (int)pSeq->_size; i++)
		{
			pSeq->_a[i - 1] = pSeq->_a[i];
		}
		pSeq->_size--;
		printf("ɾ���ɹ�\n");
	}
}

//����
int SeqFind(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
		return -1;
	}
	else
	{
		for (int i = 0; i < (int)pSeq->_size; i++)
		{
			if (pSeq->_a[i] == x)
			{
				return i;
			}
		}
		return -1;
	}
}

//�޸�
void SeqModify(SeqList* pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		assert(pos < pSeq->_size);
		pSeq->_a[pos] = x;
		printf("�޸ĳɹ�\n");
	}
}

//����
void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//ð������
void BubbleSort(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
		return;
	}
	for (int i = 0; i < (int)pSeq->_size - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < (int)pSeq->_size - i - 1; j++)
		{
			if (pSeq->_a[j]>pSeq->_a[j + 1])
			{
				flag = 1;
				Swap(&pSeq->_a[j], &pSeq->_a[j + 1]);
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
void SelectSort(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
		return;
	}
	int left = 0;
	int right = pSeq->_size - 1;
	while (left < right)
	{
		int i = 0;
		int min = left;
		int max = left;
		for (i = left; i <= right; i++)
		{
			if (pSeq->_a[i] < pSeq->_a[min])
			{
				min = i;
			}
			if (pSeq->_a[i] > pSeq->_a[max])
			{
				max = i;
			}
		}
		if (min != left)
		{
			Swap(&pSeq->_a[min], &pSeq->_a[left]);
		}
		if (max == left)
		{
			max = min;
		}
		if (max != right)
		{
			Swap(&pSeq->_a[max], &pSeq->_a[right]);
		}
		left++;
		right--;
	}
	printf("����ɹ�\n");
}

//���ֲ���
int BinarySearch(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("��˳���Ϊ��\n");
		return -1;
	}
	int left = 0;
	int right = pSeq->_size - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (pSeq->_a[mid] < x)
		{
			left = mid + 1;
		}
		else if (pSeq->_a[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}