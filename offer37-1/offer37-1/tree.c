#include"tree.h"
//反序列化二叉树
BSTreeNode *deserializationTree(int preOrder[], int size, int *pUsedSize)
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
	root->left = deserializationTree(preOrder + 1, size - 1, &leftUse);
	root->right = deserializationTree(preOrder + 1 + leftUse, size - 1 - leftUse, &rightUse);


	*pUsedSize = 1 + leftUse + rightUse;
	return root;
}
//序列化二叉树
void  serializeTree(BSTreeNode *root)
{

	if (root == NULL) {
		
		printf("%d ",-1);
		return;
	}
	printf("%d ", root->data);
	serializeTree(root->left);
	serializeTree(root->right);
}
int main()
{
	int preOrder[] = { 1, 2, 4, -1, -1, -1, 3 ,-1,-1};
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;
	BSTreeNode *root = CreateTree(preOrder, size, &usedSize);
	Preorder(root); printf("\n");
	system("pause");
	return 0;
}