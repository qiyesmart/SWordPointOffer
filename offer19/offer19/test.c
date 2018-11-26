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
void Preorder(BSTreeNode *root)
{
	// 终止条件
	if (root == NULL) {
		return;
	}

	// 根
	printf("%d ", root->data);
	// 左子树，子问题用递归处理
	Preorder(root->left);
	// 右子树，子问题用递归处理
	Preorder(root->right);
}


#include "satck.h"

//求镜像
//递归
void  Mirror1(BSTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	Mirror1(root->left);
	Mirror1(root->right);

	BSTreeNode *t = root->left;
	root->left = root->right;
	root->right = t;

}
//非递归
void  Mirror2(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	//last上一个被遍历过的结点
	BSTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//遍历左子树
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top的左子树已经遍历过了
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			//如果右子树被遍历过了
			StackPop(&stack);
			BSTreeNode *t = root->left;
			root->left = root->right;
			root->right = t;
			//记录被遍历的结点
			last = top;
		}
		else
		{
			//如果右子树没有被遍历
			cur = top->right;
		}
	}
}
void test()
{
	int preOrder[] = { 1, 2, 4, -1, -1, -1, 3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	BSTreeNode *root = CreateTree(preOrder, size, &usedSize);
	Mirror1(root);
	Preorder(root);

	Mirror2(root);
	Preorder(root);
}

int main()
{
	test();
	system("pause");
	return 0;
}