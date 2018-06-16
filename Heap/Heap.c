#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//��ʼ����
void HeapInit(Heap* hp, HeapDateType* a, size_t n)
{
    assert(hp);
    hp->_a = (HeapDateType*)malloc(n*sizeof(HeapDateType));
    memcpy(hp->_a, a, n*sizeof(HeapDateType));
    hp->_size = n;
    hp->_capacity = n;
}

//����
void Swap(HeapDateType *x, HeapDateType *y)
{
    *x ^= *y ^= *x ^= *y;
}

//�Զ����µ���
void HeapAdjustDown(Heap* hp, int root)
{
    assert(hp);
    int parent = root;
    int child = parent * 2 + 1;
    int flag = 0; //�������
    while (child < (int)hp->_size)
    {
        if (child + 1 < (int)hp->_size) //����Һ��Ӵ��ڣ��Ƚ����Һ��ӵ���ֵ��С
        {
            if (hp->_a[child] < hp->_a[child + 1])
            {
                child++; //childȡ��ֵ����
            }
        }
        if (hp->_a[child]>hp->_a[parent]) //������ӽڵ���ֵ����˫�׽ڵ���ֵ�����н���
        {
            flag = 1;
            Swap(hp->_a + child, hp->_a + parent);
        }
        if (flag == 0) //û�е�����˵��������Ǵ�ѣ�ѭ���˳�
        {
            break;
        }
        //����һ�ε����󣬴�ʱ���ܵ���������������ѵ����ʣ��������µ�������ֱ������ѵ�����
        parent = child;
        child = parent * 2 + 1;
    }
}

//�Ե����ϵ���
void HeapAdjustUp(Heap* hp, int child)
{
    assert(hp);
    assert(child > 0 && child < (int)hp->_size);
    while (child)
    {
        HeapDateType parent = (child - 1) / 2;
        if (hp->_a[parent] < hp->_a[child]) //������ӵ���ֵ����˫�׵���ֵ�����߽���
        {
            Swap(hp->_a + parent, hp->_a + child);
            child = parent; //����·�����ϵ���
        }
        else //�������Ҫ����˵����ʱ�����Ǵ�ѣ�ѭ���˳�
        {
            break;
        }
    }
}

//������
void HeapMake(Heap* hp)
{
    int parent = (int)(hp->_size - 2) / 2;
    for (; parent >= 0; parent--) //�����һ����Ҷ�ӽڵ㿪ʼ������һֱ�����ڵ�Ϊֹ
    {
        HeapAdjustDown(hp, parent); //�Զ����µ���
    }
}

//����
void CheckCapacity(Heap *hp)
{
    assert(hp);
    if (hp->_size >= hp->_capacity)
    {
        HeapDateType* ptr = (HeapDateType*)realloc(hp->_a, (hp->_capacity + 2)*sizeof(HeapDateType));
        assert(ptr);
        hp->_a = ptr;
        hp->_capacity += 2;
    }
}

//����
void HeapPush(Heap* hp, HeapDateType x)
{
    assert(hp);
    CheckCapacity(hp);
    hp->_a[hp->_size] = x; //���뵽���һ���ڵ�
    hp->_size++;
    HeapAdjustUp(hp, hp->_size - 1); //�Ե����ϵ���
}

//ɾ��
void HeapPop(Heap* hp)
{
    assert(hp);
    if (hp->_size == 0)
    {
        return;
    }
    else if (hp->_size == 1)
    {
        hp->_size--;
    }
    else //������2���ڵ�
    {
        hp->_a[0] = hp->_a[hp->_size - 1]; //�����һ���ڵ��滻����һ���ڵ�
        hp->_size--;
        HeapAdjustDown(hp, 0); //�Զ����µ���
    }
}

//�ڵ����
size_t GetHeapSize(Heap* hp)
{
    assert(hp);
    return hp->_size;
}

//�п�
size_t HeapEmpty(Heap* hp)
{
    assert(hp);
    if (hp->_size)
    {
        return 0; //��Ϊ��
    }
    return 1; //Ϊ��
}

//��ȡ�Ѷ�Ԫ��
HeapDateType HeapTop(Heap* hp)
{
    assert(hp&&hp->_size > 0);
    return hp->_a[0];
}

//�����򣨽��󶥶�->����
void HeapSort(Heap* hp)
{
    assert(hp);
    int sz = hp->_size;
    while (hp->_size>1)
    {
        Swap(&hp->_a[0], &hp->_a[hp->_size - 1]); //����һ���ڵ�����һ���ڵ����ֵ����
        hp->_size--; //���һ���ڵ���Ϊ��ǰ���ֵ���ɲ��ÿ���
        HeapAdjustDown(hp, 0); //�Զ����µ���
    }
    hp->_size = sz;
}

//���
void HeapPrint(Heap *hp)
{
    for (int i = 0; i < (int)hp->_size; i++)
    {
        printf("%d ", hp->_a[i]);
    }
    printf("\n");
}

//TopK���⣺��N������ѡȡǰK����Сֵ���������
//ʱ�临�Ӷȣ�N*logK
void HeapTopK(HeapDateType* a, int size, int k)
{
    Heap hp;
    HeapInit(&hp, a, k);
    HeapMake(&hp); //��ȡ����ǰk��ֵ�����
    for (int i = k; i < size; i++) //��K֮�����αȽ�
    {
        if (a[i] < hp._a[0]) //���k֮���бȵ�ǰ�Ѷ�С��ֵ
        {
            hp._a[0] = a[i]; //�����滻�Ѷ�ֵ
            HeapAdjustDown(&hp, 0); //�Զ����µ���
        }
    }
    printf("ǰ%d����Сֵ��", k);
    HeapPrint(&hp);
}