#include"tree.h"

void ConvertNode(BSTreeNode *root, BSTreeNode **pLastNodeLast)
{
	if (root == NULL)
	{
		return;
	}
	BSTreeNode *cur = root;
	if (cur->left != NULL)
	{
		ConvertNode(cur->left, pLastNodeLast);
	}
	cur->left = *pLastNodeLast;
	if (*pLastNodeLast != NULL)
	{
		(*pLastNodeLast)->right = cur;
	}
	*pLastNodeLast = cur;
	if (cur->right != NULL)
	{
		ConvertNode(cur->right, pLastNodeLast);
	}
}
BSTreeNode *Convert(BSTreeNode * root)
{
	BSTreeNode * pLastNodeLast = NULL;
	ConvertNode(root, &pLastNodeLast);

	BSTreeNode * pHeadNode = pLastNodeLast;
	while (pHeadNode != NULL&&pHeadNode->left != NULL)
	{
		pHeadNode = pHeadNode->left;
	}
	return pHeadNode;
}
int BSTreeInsert2(BSTreeNode **root, DataType key)
{
	if (*root == NULL)
	{
		BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		*root = node;
		return 1;
	}
	if (key == (*root)->key)
	{
		return 0;
	}
	else if (key < (*root)->key)
	{
		//这种做法不对，改变的只是栈上临时变量的值
		//BSTreeNode *child=(*root)-left;
		//return BSTreeInsert2(&child,key);
		return BSTreeInsert2(&(*root)->left, key);
	}
	else
	{
		return BSTreeInsert2(&(*root)->right, key);
	}
}
int main()
{
	int r;
	BSTreeNode *root = NULL;
	r = BSTreeInsert2(&root, 5);
	r = BSTreeInsert2(&root, 3);
	r = BSTreeInsert2(&root, 7);
	r = BSTreeInsert2(&root, 1);
	r = BSTreeInsert2(&root, 4);
	r = BSTreeInsert2(&root, 6);
	r = BSTreeInsert2(&root, 8);
	r = BSTreeInsert2(&root, 0);
	r = BSTreeInsert2(&root, 2);
	r = BSTreeInsert2(&root, 9);
	
	BSTreeNode *cu = Convert(root);

	system("pause");
	return 0;
}