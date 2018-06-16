#define _CRT_SECURE_NO_WARNINGS 1

#include "BSTree.h"

//�������
BSTreeNode* BuyBSTreeNode(DataType x)
{
    BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
    assert(node);
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

//����
int BSTreeInsert(BSTreeNode** pptree, DataType x)
{
    if (*pptree == NULL)
    {
        *pptree = BuyBSTreeNode(x);
        return 1;
    }

    BSTreeNode* prev = *pptree;
    BSTreeNode* cur = *pptree;
    while (cur) //�ҵ�Ҫ�����λ��
    {
        prev = cur; //����Ҫ����λ�õ�˫�׽ڵ�
        if (cur->_data > x)
        {
            cur = cur->_left;
        }
        else if (cur->_data < x)
        {
            cur = cur->_right;
        }
        else //�����ȣ�˵��X�Ѵ��ڣ����ò���
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

//ɾ��
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
        else //�ҵ��˱�ɾ���ڵ��λ��
        {
            //1.��Ϊ��
            //2.��Ϊ��
            //3.���Ҷ���Ϊ��
            if (cur->_left == NULL) //��ɾ���ڵ�����Ϊ��ʱ
            {
                if (cur == *pptree) //����ɾ���ڵ��Ǹ��ڵ㣬�������Һ�����Ϊ��
                {
                    *pptree = cur->_right;
                }
                else //�жϱ�ɾ���ڵ����丸�׵���һ�����ӣ��������Һ��Ӷ�������λ��
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
            else if (cur->_right == NULL) //��ɾ���ڵ��Һ���Ϊ��ʱ
            {
                if (cur == *pptree) //����ɾ���ڵ��Ǹ��ڵ㣬������������Ϊ��
                {
                    *pptree = cur->_left;
                }
                else //�жϱ�ɾ���ڵ����丸�׵���һ�����ӣ����������Ӷ�������λ��
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
            else //�����Һ��Ӷ���Ϊ��ʱ��������������Ѱ�����������ĵ�һ���ڵ㣬���������ɾ���ڵ��У��ٴ���ýڵ��ɾ������
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

//����
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

//�������
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

//����
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

//�ݹ����
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

//�ݹ�ɾ��
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
        //1.��Ϊ��
        //2.��Ϊ��
        //3.���Ҷ���Ϊ��
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
            BSTreeNode* subleft = (*pptree)->_right; //����������Ѱ�����������ĵ�һ���ڵ�
            while (subleft->_left)
            {
                subleft = subleft->_left;
            }
            (*pptree)->_data = subleft->_data; //�����������ĵ�һ���ڵ������ɾ���ڵ���
            return BSTreeRemoveR(&(*pptree)->_right, subleft->_data); //�����⣺����ڱ�ɾ���ڵ����������ɾ���ղ�������Ľڵ�
        }
    }
}

//�ݹ����
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