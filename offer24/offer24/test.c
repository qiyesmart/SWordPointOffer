#include<stdio.h>
#include<stdlib.h>
int BstSearch(int sequece[], int length)
{
	if (sequece == NULL || length <= 0)
	{
		return 0;
	}
	int root = sequece[length - 1];
	
	//����������С�ڸ����Ľ��
		int i = 0;
		for (; i < length - 1; i++)
		{
			if (sequece[i]>root)
			{
				break;
			}
		}
		//�������������ڸ����Ľ��
		int j = i;
		for (; j < length - 1; j++)
		{
			if (sequece[j]<root)
			{
				return 0;
			}
		}
		//�ж��������ǲ��Ƕ���������
		int left = 1;
		if (i>0)
		{
			left = BstSearch(sequece, i);
		}
		//�ж��������ǲ��Ƕ���������
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
		printf("�������������������");
	}
	else
	{
		printf("���������������������");
	}
	system("pause");
	return 0;
}