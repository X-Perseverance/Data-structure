#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	DataType _data;
}BSTreeNode;

// ·ÇµÝ¹é 
BSTreeNode* BuyBSTreeNode(DataType x);
int BSTreeInsert(BSTreeNode** pptree, DataType x);
int BSTreeRemove(BSTreeNode** pptree, DataType x);
const BSTreeNode* BSTreeFind(BSTreeNode* ptree, DataType x);
void BSTreeInOrder(BSTreeNode* ptree);
void BSTreeDestory(BSTreeNode* ptree);

// µÝ¹é 
int BSTreeInsertR(BSTreeNode** pptree, DataType x);
int BSTreeRemoveR(BSTreeNode** pptree, DataType x);
const BSTreeNode* BSTreeFindR(BSTreeNode* ptree, DataType x);

#endif __BSTREE_H__