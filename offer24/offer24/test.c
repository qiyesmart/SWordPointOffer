#include<stdio.h>
#include<stdlib.h>
int BstSearch(int sequece[], int length)
{
	if (sequece == NULL || length <= 0)
	{
		return 0;
	}
	int root = sequece[length - 1];
	
	//搜索左子树小于根结点的结点
		int i = 0;
		for (; i < length - 1; i++)
		{
			if (sequece[i]>root)
			{
				break;
			}
		}
		//搜索右子树大于根结点的结点
		int j = i;
		for (; j < length - 1; j++)
		{
			if (sequece[j]<root)
			{
				return 0;
			}
		}
		//判断左子树是不是二叉搜索树
		int left = 1;
		if (i>0)
		{
			left = BstSearch(sequece, i);
		}
		//判断右子树是不是二叉搜索树
		int right = 1;
		if (i < length - 1)
		{
			right = BstSearch(sequece+i, length-i-1);
		}
		return(left&&right);
}
int main()
{
	int arr[7] = { 5, 7, 6, 9, 11, 10, 8 };
	int d = BstSearch(arr, 7);
	if (d == 1)
	{
		printf("是搜索二叉树后序遍历");
	}
	else
	{
		printf("不是搜索二叉树后序遍历");
	}
	system("pause");
	return 0;
}