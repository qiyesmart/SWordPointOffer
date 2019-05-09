#pragma once


#include<stdio.h>
#include<stdlib.h>

typedef int  DataType;

typedef struct  BSTreeNode{
	DataType data;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
} BSTreeNode;

BSTreeNode *CreateNode(int data)
{
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
BSTreeNode *CreateTree(int preOrder[], int size, int *pUsedSize)
{
	if (size <= 0)
	{
		*pUsedSize = 0;
		return NULL;
	}
	int leftUse, rightUse;
	int rootValue = preOrder[0];
	if (rootValue == -1)
	{
		*pUsedSize = 1;
		return NULL;
	}
	BSTreeNode *root = CreateNode(rootValue);
	root->left = CreateTree(preOrder + 1, size - 1, &leftUse);
	root->right = CreateTree(preOrder + 1 + leftUse, size - 1 - leftUse, &rightUse);

	
	*pUsedSize = 1 + leftUse + rightUse;
	return root;
}