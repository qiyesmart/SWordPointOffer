#define _CRT_SECURE_NO_WARNINGS 1
//��ֵ�������η�
//��ȫ�治��Ч
#include<stdio.h>
#include<stdlib.h>
int Power(int base, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= base;
	}
	return result;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d", Power(a, b));
	system("pause");
	return 0;
}

//ȫ�浫����Ч������ָ��Ϊ0�����������
#include<stdio.h>
#include<stdlib.h>
bool InvalidInput = false;
double  PowerWithAbsn(double base, int absn)
{
	double result1 = 1.0;
	for (int i = 0; i <absn; i++)
	{
		result1 *= base;
	}
	return result1;
}
double Power(double base, int n)
{
	InvalidInput = false;
	int absn = 0;
	double result = 0;
	//����Ϊ0��ָ��<=0
	if(base == 0.0&&n<=0)
	{
		InvalidInput = true;
		return 0.0;
	}
	//ָ��Ϊ����
	else if (n < 0)
	{
	    absn = (-n);
		result = PowerWithAbsn(base, absn);
		if (n < 0)
			result = 1.0 / result;
		return result;
	}
	//ָ��Ϊ����
	else
	{
		absn = n;
		result = PowerWithAbsn(base, absn);
		return result;
	}
}

int main()
{
	double a = 0.0;
	int b = 0;
	scanf("%lf %d", &a, &b);
	printf("%lf", Power(a, b));
	system("pause");
	return 0;
}

//ȫ���ָ�Ч
#include<stdio.h>
#include<stdlib.h>
bool InvalidInput = false;
double  PowerWithAbsn(double base, int absn)
{
	if (absn == 0)
	{
		return 1;
	}
	if (absn == 1)
	{
		return base;
	}
	double result1 = PowerWithAbsn(base, absn / 2);
	result1 *= result1;
	//�ж�nΪż����������
	if (absn % 2 == 1)
	{
		result1 = result1*base;
	}
	return result1;
}
double Power(double base, int n)
{
	InvalidInput = false;
	int absn = 0;
	double result = 0;
	//����Ϊ0��ָ��<=0
	if (base == 0.0&&n <= 0)
	{
		InvalidInput = true;
		return 0.0;
	}
	//ָ��Ϊ����
	else if (n < 0)
	{
		absn = (-n);
		result = PowerWithAbsn(base, absn);
		if (n < 0)
			result = 1.0 / result;
		return result;
	}
	//ָ��Ϊ����
	else
	{
		absn = n;
		result = PowerWithAbsn(base, absn);
		return result;
	}
}

int main()
{
	double a = 0.0;
	int b = 0;
	scanf("%lf %d", &a, &b);
	printf("%lf", Power(a, b));
	system("pause");
	return 0;
}
