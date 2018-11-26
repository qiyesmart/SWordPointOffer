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

	//���ϴ󱨸�ʵ��ʹ�����
	*pUsedSize = 1 + leftUse + rightUse;
	return root;
}
void Preorder(BSTreeNode *root)
{
	// ��ֹ����
	if (root == NULL) {
		return;
	}

	// ��
	printf("%d ", root->data);
	// ���������������õݹ鴦��
	Preorder(root->left);
	// ���������������õݹ鴦��
	Preorder(root->right);
}


#include "satck.h"

//����
//�ݹ�
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
//�ǵݹ�
void  Mirror2(BSTreeNode *root)
{
	Stack  stack;
	StackInit(&stack);
	//last��һ�����������Ľ��
	BSTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		//����������
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top���������Ѿ���������
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			//�������������������
			StackPop(&stack);
			BSTreeNode *t = root->left;
			root->left = root->right;
			root->right = t;
			//��¼�������Ľ��
			last = top;
		}
		else
		{
			//���������û�б�����
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