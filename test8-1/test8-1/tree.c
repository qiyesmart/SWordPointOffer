#include"stack.h"
#include"tree.h"



//非递归中序遍历
void    InOrderLoopFind(BSTreeNode *root,DataType  data1)
{
	Stack  stack;
	StackInit(&stack);
	BSTreeNode *cur, *top,*cur1;
	cur = root;
	
	while (cur != NULL || !StackEmpty(&stack))
	{
		//遍历左子树
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top的左子树已经遍历
		top = StackTop(&stack);
		StackPop(&stack);
		//在树中遍历到给定的那个结点
		if (top->data == data1)
		{
			cur1 = top->right;
			while (cur1 != NULL || !StackEmpty(&stack))
			{
				//遍历左子树
				while (cur1 != NULL)
				{
					StackPush(&stack, cur1);
					cur1 = cur1->left;
				}
				//top的左子树已经遍历
				top = StackTop(&stack);
				StackPop(&stack);
				//打印当前结点
				printf("%d", top->data);
			}
		}
		//利用子问题的思想遍历top右子树
		cur = top->right;
	}
	
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

	//向老大报告实际使用情况
	*pUsedSize = 1 + leftUse + rightUse;
	return root;
}
int main()
{
	int preOrder[] = { 1, 2, 4, -1, -1, -1, 3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	int a = 2;
	BSTreeNode *root = CreateTree(preOrder, size, &usedSize);
	InOrderLoopFind(root, a);
	InOrderLoop2(root);
	system("pause");
	return 0;
}