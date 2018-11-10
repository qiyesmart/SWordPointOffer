#define _CRT_SECURE_NO_WARNINGS 1
//数值的整数次方
//不全面不高效
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

//全面但不高效（考虑指数为0或负数的情况）
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
	//底数为0且指数<=0
	if(base == 0.0&&n<=0)
	{
		InvalidInput = true;
		return 0.0;
	}
	//指数为负数
	else if (n < 0)
	{
	    absn = (-n);
		result = PowerWithAbsn(base, absn);
		if (n < 0)
			result = 1.0 / result;
		return result;
	}
	//指数为正数
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

//全面又高效
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
	//判断n为偶数还是奇数
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
	//底数为0且指数<=0
	if (base == 0.0&&n <= 0)
	{
		InvalidInput = true;
		return 0.0;
	}
	//指数为负数
	else if (n < 0)
	{
		absn = (-n);
		result = PowerWithAbsn(base, absn);
		if (n < 0)
			result = 1.0 / result;
		return result;
	}
	//指数为正数
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
