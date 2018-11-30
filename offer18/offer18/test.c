#include"test.h"

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

	//向老大报告实际使用情况
	*pUsedSize = 1 + leftUse + rightUse;
	return root;
}
//判断一棵树是子树
int DoesTree(BSTreeNode *root1, BSTreeNode *root2)
{
	//到达root2叶结点
	if (root2 == NULL)
	{
		return 1;
	}
	if (root1 == NULL)
	{
		return 0;
	}
	if (root1->data != root2->data)
	{
		return 0;
	}
	return   DoesTree(root1->left, root2->left) && DoesTree(root1->right, root2->right);
}
int IsZitree(BSTreeNode *root1, BSTreeNode *root2)
{
	int result = 0;
	if (root1 != NULL&&root2 != NULL)
	{
		if (root1->data == root2->data)
		{
			result = DoesTree(root1, root2);
		}
		if (!result)
		{
			IsZitree(root1->left, root2);
		}
		if (!result)
		{
			IsZitree(root1->right, root2);
		}
	}
	return result;
}



int main()
{
	int preOrder[] = { 1, 2, 4, -1, -1, -1, 3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	BSTreeNode *root1 = CreateTree(preOrder, size, &usedSize);
	int preOrder2[] = { 1, 2, -1, -1, -1, 3 };
	int size2 = sizeof(preOrder) / sizeof(int);
	int usedSize2;
	BSTreeNode *root2 = CreateTree(preOrder2, size2, &usedSize2);
	int f = IsZitree(root1, root2);
	if (f == 1)
		printf("是子树");
	else
		printf("不是子树");
	system("pause");
	return 0;
}
