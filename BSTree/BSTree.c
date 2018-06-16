#define _CRT_SECURE_NO_WARNINGS 1

#include "BSTree.h"

//创建结点
BSTreeNode* BuyBSTreeNode(DataType x)
{
    BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
    assert(node);
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

//插入
int BSTreeInsert(BSTreeNode** pptree, DataType x)
{
    if (*pptree == NULL)
    {
        *pptree = BuyBSTreeNode(x);
        return 1;
    }

    BSTreeNode* prev = *pptree;
    BSTreeNode* cur = *pptree;
    while (cur) //找到要插入的位置
    {
        prev = cur; //保存要插入位置的双亲节点
        if (cur->_data > x)
        {
            cur = cur->_left;
        }
        else if (cur->_data < x)
        {
            cur = cur->_right;
        }
        else //如果相等，说明X已存在，不用插入
        {
            return 0;
        }
    }

    if (prev->_data > x)
    {
        prev->_left = BuyBSTreeNode(x);
    }
    else if (prev->_data < x)
    {
        prev->_right = BuyBSTreeNode(x);
    }
    return 1;
}

//删除
int BSTreeRemove(BSTreeNode** pptree, DataType x)
{
    if (*pptree == NULL)
    {
        return 0;
    }

    BSTreeNode* cur = *pptree;
    BSTreeNode* parent = *pptree;
    while (cur)
    {   
        if (cur->_data > x)
        {
            parent = cur;
            cur = cur->_left;
        }
        else if (cur->_data < x)
        {
            parent = cur;
            cur = cur->_right;
        }
        else //找到了被删除节点的位置
        {
            //1.左为空
            //2.右为空
            //3.左右都不为空
            if (cur->_left == NULL) //被删除节点左孩子为空时
            {
                if (cur == *pptree) //若被删除节点是根节点，则让其右孩子作为根
                {
                    *pptree = cur->_right;
                }
                else //判断被删除节点是其父亲的哪一个孩子，再让其右孩子顶替它的位置
                {
                    if (parent->_left == cur)
                    {
                        parent->_left = cur->_right;
                    }
                    else
                    {
                        parent->_right = cur->_right;
                    }
                }
                free(cur);
            }
            else if (cur->_right == NULL) //被删除节点右孩子为空时
            {
                if (cur == *pptree) //若被删除节点是根节点，则让其左孩子作为根
                {
                    *pptree = cur->_left;
                }
                else //判断被删除节点是其父亲的哪一个孩子，再让其左孩子顶替它的位置
                {
                    if (parent->_left == cur)
                    {
                        parent->_left = cur->_left;
                    }
                    else
                    {
                        parent->_right = cur->_left;
                    }
                }
                free(cur);
            }
            else //当左右孩子都不为空时，在它的右子树寻找中序遍历后的第一个节点，用它填补到被删除节点中，再处理该节点的删除问题
            {
                parent = cur;
                BSTreeNode* subleft = cur->_right;
                while (subleft->_left)
                {
                    parent = subleft;
                    subleft = subleft->_left;
                }
                cur->_data = subleft->_data;
                if (parent->_left == subleft)
                {
                    parent->_left = subleft->_right;
                }
                else
                {
                    parent->_right = subleft->_right;
                }
                free(subleft);
                subleft = NULL;
            }
            return 1;
        }
    }
    return 0;
}

//查找
const BSTreeNode* BSTreeFind(BSTreeNode* ptree, DataType x)
{
    if (ptree == NULL)
    {
        return NULL;
    }

    BSTreeNode* cur = ptree;
    while (cur)
    {
        if (cur->_data > x)
        {
            cur = cur->_left;
        }
        else if (cur->_data < x)
        {
            cur = cur->_right;
        }
        else
        {
            return cur;
        }
    }
    return NULL;
}

//中序遍历
void BSTreeInOrder(BSTreeNode* ptree)
{
    if (ptree == NULL)
    {
        return;
    }
    BSTreeInOrder(ptree->_left);
    printf("%d ", ptree->_data);
    BSTreeInOrder(ptree->_right);
}

//销毁
void BSTreeDestory(BSTreeNode* ptree)
{
    if (ptree == NULL)
    {
        return;
    }
    BSTreeDestory(ptree->_left);
    BSTreeDestory(ptree->_right);
    free(ptree);
}

//递归插入
int BSTreeInsertR(BSTreeNode** pptree, DataType x)
{
    if (*pptree == NULL)
    {
        *pptree = BuyBSTreeNode(x);
        return 1;
    }

    if ((*pptree)->_data > x)
    {
        return BSTreeInsertR(&(*pptree)->_left, x);
    }
    else if ((*pptree)->_data < x)
    {
        return BSTreeInsertR(&(*pptree)->_right, x);
    }
    else
    {
        return 0;
    }
}

//递归删除
int BSTreeRemoveR(BSTreeNode** pptree, DataType x)
{
    if (*pptree == NULL)
    {
        return 0;
    }

    if ((*pptree)->_data > x)
    {
        return BSTreeRemoveR(&(*pptree)->_left, x);
    }
    else if ((*pptree)->_data < x)
    {
        return BSTreeRemoveR(&(*pptree)->_right, x);
    }
    else
    {
        //1.左为空
        //2.右为空
        //3.左右都不为空
        if ((*pptree)->_left == NULL)
        {
            *pptree = (*pptree)->_right;
            return 1;
        }
        else if ((*pptree)->_right == NULL)
        {
            *pptree = (*pptree)->_left;
            return 1;
        }
        else
        {
            BSTreeNode* subleft = (*pptree)->_right; //在右子树中寻找中序遍历后的第一个节点
            while (subleft->_left)
            {
                subleft = subleft->_left;
            }
            (*pptree)->_data = subleft->_data; //用中序遍历后的第一个节点填补到被删除节点中
            return BSTreeRemoveR(&(*pptree)->_right, subleft->_data); //子问题：填补后，在被删除节点的右子树中删除刚才用于填补的节点
        }
    }
}

//递归查找
const BSTreeNode* BSTreeFindR(BSTreeNode* ptree, DataType x)
{
    if (ptree == NULL)
    {
        return NULL;
    }

    if (ptree->_data > x)
    {
        return BSTreeFindR(ptree->_left, x);
    }
    else if (ptree->_data < x)
    {
        return BSTreeFindR(ptree->_right, x);
    }
    else
    {
        return ptree;
    }
}