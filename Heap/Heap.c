#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//初始化堆
void HeapInit(Heap* hp, HeapDateType* a, size_t n)
{
    assert(hp);
    hp->_a = (HeapDateType*)malloc(n*sizeof(HeapDateType));
    memcpy(hp->_a, a, n*sizeof(HeapDateType));
    hp->_size = n;
    hp->_capacity = n;
}

//交换
void Swap(HeapDateType *x, HeapDateType *y)
{
    *x ^= *y ^= *x ^= *y;
}

//自顶向下调整
void HeapAdjustDown(Heap* hp, int root)
{
    assert(hp);
    int parent = root;
    int child = parent * 2 + 1;
    int flag = 0; //调整标记
    while (child < (int)hp->_size)
    {
        if (child + 1 < (int)hp->_size) //如果右孩子存在，比较左右孩子的数值大小
        {
            if (hp->_a[child] < hp->_a[child + 1])
            {
                child++; //child取数值大者
            }
        }
        if (hp->_a[child]>hp->_a[parent]) //如果孩子节点数值大于双亲节点数值，进行交换
        {
            flag = 1;
            Swap(hp->_a + child, hp->_a + parent);
        }
        if (flag == 0) //没有调整，说明本身就是大堆，循环退出
        {
            break;
        }
        //进行一次调整后，此时可能导致其子树不满足堆的性质，继续向下调整子树直到满足堆的性质
        parent = child;
        child = parent * 2 + 1;
    }
}

//自底向上调整
void HeapAdjustUp(Heap* hp, int child)
{
    assert(hp);
    assert(child > 0 && child < (int)hp->_size);
    while (child)
    {
        HeapDateType parent = (child - 1) / 2;
        if (hp->_a[parent] < hp->_a[child]) //如果孩子的数值大于双亲的数值，两者交换
        {
            Swap(hp->_a + parent, hp->_a + child);
            child = parent; //沿着路径向上调整
        }
        else //如果不需要调整说明此时堆已是大堆，循环退出
        {
            break;
        }
    }
}

//创建堆
void HeapMake(Heap* hp)
{
    int parent = (int)(hp->_size - 2) / 2;
    for (; parent >= 0; parent--) //从最后一个非叶子节点开始调整，一直到根节点为止
    {
        HeapAdjustDown(hp, parent); //自顶向下调整
    }
}

//扩容
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

//增加
void HeapPush(Heap* hp, HeapDateType x)
{
    assert(hp);
    CheckCapacity(hp);
    hp->_a[hp->_size] = x; //插入到最后一个节点
    hp->_size++;
    HeapAdjustUp(hp, hp->_size - 1); //自底向上调整
}

//删除
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
    else //至少有2个节点
    {
        hp->_a[0] = hp->_a[hp->_size - 1]; //将最后一个节点替换到第一个节点
        hp->_size--;
        HeapAdjustDown(hp, 0); //自顶向下调整
    }
}

//节点个数
size_t GetHeapSize(Heap* hp)
{
    assert(hp);
    return hp->_size;
}

//判空
size_t HeapEmpty(Heap* hp)
{
    assert(hp);
    if (hp->_size)
    {
        return 0; //不为空
    }
    return 1; //为空
}

//获取堆顶元素
HeapDateType HeapTop(Heap* hp)
{
    assert(hp&&hp->_size > 0);
    return hp->_a[0];
}

//堆排序（建大顶堆->升序）
void HeapSort(Heap* hp)
{
    assert(hp);
    int sz = hp->_size;
    while (hp->_size>1)
    {
        Swap(&hp->_a[0], &hp->_a[hp->_size - 1]); //将第一个节点和最后一个节点的数值交换
        hp->_size--; //最后一个节点已为当前最大值，可不用考虑
        HeapAdjustDown(hp, 0); //自顶向下调整
    }
    hp->_size = sz;
}

//输出
void HeapPrint(Heap *hp)
{
    for (int i = 0; i < (int)hp->_size; i++)
    {
        printf("%d ", hp->_a[i]);
    }
    printf("\n");
}

//TopK问题：从N个数中选取前K个最小值——建大堆
//时间复杂度：N*logK
void HeapTopK(HeapDateType* a, int size, int k)
{
    Heap hp;
    HeapInit(&hp, a, k);
    HeapMake(&hp); //先取数组前k个值建大堆
    for (int i = k; i < size; i++) //从K之后依次比较
    {
        if (a[i] < hp._a[0]) //如果k之后有比当前堆顶小的值
        {
            hp._a[0] = a[i]; //则将其替换堆顶值
            HeapAdjustDown(&hp, 0); //自顶向下调整
        }
    }
    printf("前%d个最小值：", k);
    HeapPrint(&hp);
}