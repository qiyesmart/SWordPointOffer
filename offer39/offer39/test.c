#include"btree.h"
#include"queue.h"
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

int  count_tree(BSTreeNode *root)
{
	if (root==NULL)
	{
		return 0;
	}
	int count = 0;
	//记录遍历过的层数
	int c = 0;
	Queue que;
	QueueInit(&que);
	QueuePush(&que, root);
	while (!QueueEmpty(&que))
	{

		count+=1;
		int d = QueueSize(&que);
		if (c < d)
		{
			c++;
			root = QueueFront(&que);
			QueuePop(&que);
			if (root->left)
			{
				QueuePush(&que, root->left);
			}
			if (root->right)
			{
				QueuePush(&que, root->right);
			}
		}
		else
		{
			return count;
		}
	}
	return 1;
}
//求树的高度
#define  MAX(a ,b)  ((a)>(b)? (a):(b))

int GetHeight(BSTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	//当子树有一个节点的时候，可以写，也可以不写
	//写的话，节省两次函数调用
	int nLeft = GetHeight(root->left);
	int nRight = GetHeight(root->right);
	return MAX(nLeft, nRight) + 1;
}
//判断是否为平衡树
int IsBlanced(BSTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int nLeft = GetHeight(root->left);
	int nRight = GetHeight(root->right);
	int dif = nLeft-nRight;
	if (dif==1||dif==-1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}



int main()
{
	int preOrder[] = { 1, 2, 4, -1, -1, -1, 3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	BSTreeNode *root = CreateTree(preOrder, size, &usedSize);
	int t = count_tree(root);
	printf("%d\n", t);
	int d = GetHeight(root);
	printf("%d\n", d);
	int f = IsBlanced(root);
	if (f == -1)
		printf("不是平衡树");
	else
		printf("是平衡树");
	system("pause");
	return 0;
}
