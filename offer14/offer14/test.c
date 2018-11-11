//����ģʽ
#include<stdio.h>
#include<stdlib.h>
void ReorderOddEvn(int *p, int length)
{
	if (p == NULL&&length == 0)
	{
		return;
	}
	int *begin = p;
	int *end = p + length - 1;
	while (begin < end)
	{
		//���beginָ������
		while (begin < end&&*begin % 2 == 1)
		{
			begin++;
		}
		//���endָ��ż��
		while (begin < end&&*end % 2 == 0)
		{
			end--;
		}
		if (begin < end)
		{
			int temp = *begin;
			*begin = *end;
			*end = temp;
		}
	}
}
int main()
{
	int arr1[8] = { 2, 4, 6, 8, 1, 3, 5, 7 };
	ReorderOddEvn(arr1, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr1[i]);
	}
	system("pause");
	return 0;
}

//ͨ��ģʽ
#include<stdio.h>
#include<stdlib.h>
int IsEven(int n)
{
	return(n % 2) == 1;
}
void ReorderOddEvn(int *p, int length)
{
	if (p == NULL&&length == 0)
	{
		return;
	}
	int *begin = p;
	int *end = p + length - 1;
	while (begin < end)
	{
		while (begin < end&&!IsEven(*begin))
		{
			begin++;
		}
		while (begin < end&&IsEven(*end))
		{
			end--;
		}
		if (begin < end)
		{
			int temp = *begin;
			*begin = *end;
			*end = temp;
		}
	}
}
int main()
{
	int arr1[8] = { 2, 4, 6, 8, 1, 3, 5, 7 };
	ReorderOddEvn(arr1, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr1[i]);
	}
	system("pause");
	return 0;
}