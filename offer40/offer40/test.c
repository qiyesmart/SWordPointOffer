//��������ֻ����һ�ε���
#include<stdio.h>
#include<stdlib.h>
void FindDiffNum(int arr[], int sz, int *px, int *py)
{
	int num = 0;
	int i = 0;
	//��¼������������������ж�����λ�����ұ�Ϊ1����λ
	int pos = 0;
	//1.ȫ���������
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//�ҳ�������ж��������ұ���1����λ
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//�������
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px ^= arr[i];
		}
		else
		{
			*py ^= arr[i];
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 7, 1, 2, 3, 4, 9 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	int n1 = 0;
	int n2 = 0;
	FindDiffNum(arr, sz, &n1, &n2);
	printf("%d %d", n1, n2);
	system("pause");
	return 0;
}