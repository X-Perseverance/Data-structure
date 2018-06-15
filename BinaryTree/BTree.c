#define _CRT_SECURE_NO_WARNINGS 1

#include "BTree.h"
#include "Queue.h"
#include "stack.h"

//�����ڵ�
BTNode* BuyBTNode(BTDataType x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

//����������
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid) //
{
    BTNode* root = NULL;
    if (a[*pIndex] != invalid)
    {
        root = BuyBTNode(a[*pIndex]);
        (*pIndex)++;
        root->_left = CreateBTree(a, pIndex, invalid); //��ݹ�
        (*pIndex)++;
        root->_right = CreateBTree(a, pIndex, invalid); //�ҵݹ�
    }
    return root;
}

//�������
void BTreePrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->_data); //���ʸ�
    BTreePrevOrder(root->_left); //��ݹ�
    BTreePrevOrder(root->_right); //�ҵݹ�
}

//�������
void BTreeInOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    BTreeInOrder(root->_left); //��ݹ�
    printf("%d ", root->_data); //���ʸ�
    BTreeInOrder(root->_right); //�ҵݹ�
}

//�������
void BTreePostOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    BTreePostOrder(root->_left); //��ݹ�
    BTreePostOrder(root->_right); //�ҵݹ�
    printf("%d ", root->_data); //���ʸ�
}

//�������
void BTreeLevelOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    Queue q;
    QueueInit(&q);
    QueuePush(&q, root);
    while (!QueueEmpty(&q))
    {
        QDataType first = QueueFront(&q);
        QueuePop(&q);
        printf("%d ", first->_data);
        if (first->_left)
        {
            QueuePush(&q, first->_left);
        }
        if (first->_right)
        {
            QueuePush(&q, first->_right);
        }
    }
}

//�ܽڵ���
//�����⣺ÿ�����Ľڵ���=�����ĸ��ڵ�(1)+�������Ľڵ���+�������Ľڵ���
size_t BTreeSize(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + BTreeSize(root->_left) + BTreeSize(root->_right);
}

//Ҷ�ӽڵ���
//�����⣺ÿ������Ҷ�ӽڵ���=��������Ҷ�ӽڵ���+��������Ҷ�ӽڵ���
size_t BTreeLeafSize(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->_left == NULL&&root->_right == NULL)
    {
        return 1;
    }
    return BTreeLeafSize(root->_left) + BTreeLeafSize(root->_right);
}

//��K��ڵ���
//�����⣺ÿ�����ĵ�K��ڵ���=�������ĵ�k-1��ڵ���+�������ĵ�k-1��ڵ���
size_t BTreeKLevelSize(BTNode* root, size_t k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }
    return BTreeKLevelSize(root->_left, k - 1) + BTreeKLevelSize(root->_right, k - 1);
}

//���
//������:ÿ���������=��������Ⱥ�������������߽ϴ�ֵ+1
size_t BTreeDepth(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    size_t LeftDepth = BTreeDepth(root->_left);
    size_t RightDepth = BTreeDepth(root->_right);
    return LeftDepth > RightDepth ? (LeftDepth + 1) : (RightDepth + 1);
}

//����
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->_data == x)
    {
        return root;
    }
    BTNode* ret = BTreeFind(root->_left, x);
    if (ret)
    {
        return ret;
    }
    return BTreeFind(root->_right, x);
}

//�ж���ȫ������ 
int IsCompleteBTree(BTNode* root)
{
    if (root == NULL)
    {
        return 1;
    }
    Queue q;
    QueueInit(&q);
    QueuePush(&q, root);
    while (!QueueEmpty(&q)) //�ҵ�������ĵ�һ��NULL
    {
        QDataType first = QueueFront(&q);
        if (first == NULL)
        {
            break;
        }
        QueuePop(&q);
        QueuePush(&q, first->_left);
        QueuePush(&q, first->_right);
    }
    while (!QueueEmpty(&q)) //�ӵ�һ��NULL���ж��Ƿ��з�NULLֵ����
    {
        QDataType first = QueueFront(&q);
        if (first) //�����ַ�NULLֵ����Ϊ����ȫ������
        {
            return 0;
        }
        QueuePop(&q);
    }
    return 1; //ֱ������Ϊ��Ҳû�г��ַ�NULLֵ����Ϊ��ȫ������
}

//�ж���ȫ��������flag�ķ�ʽ�ж� 
int IsCompleteBTree1(BTNode* root)
{
    if (root == NULL)
    {
        return 1;
    }
    int flag = 0;
    Queue q;
    QueueInit(&q);
    QueuePush(&q, root);
    while (!QueueEmpty(&q))
    {
        QDataType first = QueueFront(&q);
        QueuePop(&q);
        if (first->_left==NULL) //������
        {
            flag = 1;
        }
        else
        {
            if (flag == 1)
            {
                return 0;
            }
            QueuePush(&q, first->_left);
        }
        if (first->_right == NULL) //������
        {
            flag = 1;
        }
        else
        {
            if (flag == 1)
            {
                return 0;
            }
            QueuePush(&q, first->_right);
        }
    }
    return 1;
}

//�ǵݹ��������
void BTreePrevOrderNonR(BTNode* root)
{
    Stack s;
    StackInit(&s);
    BTNode* cur = root;
    while (cur || StackEmpty(&s) != 0) 
        //���cur��NULL����˵����ǰ�ڵ�δ���������ջs��Ϊ�գ���˵��������δ������ֻ�е�������Ϊ0ʱ����˵��������������
    {
        while (cur)
        {
            printf("%d ", cur->_data);
            StackPush(&s, cur);
            cur = cur->_left;
        }
        BTNode* top = StackTop(&s);
        StackPop(&s);
        cur = top->_right;
    }
}

//�ǵݹ��������
void BTreeInOrderNonR(BTNode* root)
{
    Stack s;
    StackInit(&s);
    BTNode* cur = root;
    while (cur || StackEmpty(&s) != 0)
    {
        while (cur)
        {
            StackPush(&s, cur);
            cur = cur->_left;
        }
        BTNode* top = StackTop(&s);
        printf("%d ", top->_data);
        StackPop(&s);
        cur = top->_right;
    }
}

//�ǵݹ�������
void BTreePostOrderNonR(BTNode* root)
{
    Stack s;
    StackInit(&s);
    BTNode* cur = root;
    BTNode* last = NULL; //last��¼��һ�η��ʽڵ㣬��Ϊ���������ʱ��
    while (cur || StackEmpty(&s) != 0)
    {
        while (cur)
        {
            StackPush(&s, cur);
            cur = cur->_left;
        }
        BTNode* top = StackTop(&s);
        if (top->_right == last || top->_right == NULL) //���top->_right == last��˵���������ϴ��ѷ��ʹ�
        {
            printf("%d ", top->_data);
            last = top; //����last
            StackPop(&s);
        }
        else
        {
            cur = top->_right;
        }
    }
}