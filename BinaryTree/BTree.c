#define _CRT_SECURE_NO_WARNINGS 1

#include "BTree.h"
#include "Queue.h"
#include "stack.h"

//创建节点
BTNode* BuyBTNode(BTDataType x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

//创建二叉树
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid) //
{
    BTNode* root = NULL;
    if (a[*pIndex] != invalid)
    {
        root = BuyBTNode(a[*pIndex]);
        (*pIndex)++;
        root->_left = CreateBTree(a, pIndex, invalid); //左递归
        (*pIndex)++;
        root->_right = CreateBTree(a, pIndex, invalid); //右递归
    }
    return root;
}

//先序遍历
void BTreePrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->_data); //访问根
    BTreePrevOrder(root->_left); //左递归
    BTreePrevOrder(root->_right); //右递归
}

//中序遍历
void BTreeInOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    BTreeInOrder(root->_left); //左递归
    printf("%d ", root->_data); //访问根
    BTreeInOrder(root->_right); //右递归
}

//后序遍历
void BTreePostOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    BTreePostOrder(root->_left); //左递归
    BTreePostOrder(root->_right); //右递归
    printf("%d ", root->_data); //访问根
}

//层序遍历
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

//总节点数
//子问题：每棵树的节点数=该树的根节点(1)+左子树的节点数+右子树的节点数
size_t BTreeSize(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + BTreeSize(root->_left) + BTreeSize(root->_right);
}

//叶子节点数
//子问题：每棵树的叶子节点数=左子树的叶子节点数+右子树的叶子节点数
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

//第K层节点数
//子问题：每棵树的第K层节点数=左子树的第k-1层节点数+右子树的第k-1层节点数
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

//深度
//子问题:每棵树的深度=左子树深度和右子树深度两者较大值+1
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

//查找
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

//判断完全二叉树 
int IsCompleteBTree(BTNode* root)
{
    if (root == NULL)
    {
        return 1;
    }
    Queue q;
    QueueInit(&q);
    QueuePush(&q, root);
    while (!QueueEmpty(&q)) //找到队列里的第一个NULL
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
    while (!QueueEmpty(&q)) //从第一个NULL后，判断是否有非NULL值出现
    {
        QDataType first = QueueFront(&q);
        if (first) //若出现非NULL值，则为非完全二叉树
        {
            return 0;
        }
        QueuePop(&q);
    }
    return 1; //直到队列为空也没有出现非NULL值，则为完全二叉树
}

//判断完全二叉树，flag的方式判断 
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
        if (first->_left==NULL) //左子树
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
        if (first->_right == NULL) //右子树
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

//非递归先序遍历
void BTreePrevOrderNonR(BTNode* root)
{
    Stack s;
    StackInit(&s);
    BTNode* cur = root;
    while (cur || StackEmpty(&s) != 0) 
        //如果cur非NULL，则说明当前节点未遍历；如果栈s不为空，则说明右子树未遍历；只有当两个都为0时，才说明整个树遍历完
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

//非递归中序遍历
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

//非递归后序遍历
void BTreePostOrderNonR(BTNode* root)
{
    Stack s;
    StackInit(&s);
    BTNode* cur = root;
    BTNode* last = NULL; //last记录上一次访问节点，作为右子树访问标记
    while (cur || StackEmpty(&s) != 0)
    {
        while (cur)
        {
            StackPush(&s, cur);
            cur = cur->_left;
        }
        BTNode* top = StackTop(&s);
        if (top->_right == last || top->_right == NULL) //如果top->_right == last，说明右子树上次已访问过
        {
            printf("%d ", top->_data);
            last = top; //更新last
            StackPop(&s);
        }
        else
        {
            cur = top->_right;
        }
    }
}