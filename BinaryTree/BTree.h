#ifndef __BTree_h__
#define __BTree_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* _left; //左孩子
    struct BinaryTreeNode* _right; //右孩子
    BTDataType _data; //节点数据
}BTNode;

BTNode* BuyBTNode(BTDataType x);
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid);

void BTreePrevOrder(BTNode* root);
void BTreeInOrder(BTNode* root);
void BTreePostOrder(BTNode* root);
void BTreeLevelOrder(BTNode* root);

size_t BTreeSize(BTNode* root);
size_t BTreeLeafSize(BTNode* root);
size_t BTreeKLevelSize(BTNode* root, size_t k);
size_t BTreeDepth(BTNode* root);
BTNode* BTreeFind(BTNode* root, BTDataType x);

int IsCompleteBTree(BTNode* root);
int IsCompleteBTree1(BTNode* root);
 
void BTreePrevOrderNonR(BTNode* root);
void BTreeInOrderNonR(BTNode* root);
void BTreePostOrderNonR(BTNode* root);

#endif __BTree_h__