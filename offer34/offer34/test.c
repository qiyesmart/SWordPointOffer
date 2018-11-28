#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int IsUgly(int number)
{
	while (number % 2 == 0)
	{
		number /= 2;
	}
	while (number % 3 == 0)
	{
		number /= 3;
	}
	while (number % 5 == 0)
	{
		number /= 5;
	}
	return (number == 1) ? 1 : 0;
}
//求丑数1
int GetUglyNumber1(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		++number;
		if (IsUgly(number))
		{
			++uglyFound;
        }
	}
	return number;
}
int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	 min = (min < number3) ? min : number3;
	 return min;
}
//求丑数2
int GetUglyNumber2(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	//用来存放丑数数组
	int  *puglyNubmers; 
	puglyNubmers = (int*)malloc(sizeof(int)*index);
	if (puglyNubmers != NULL)
	{
		for (int i = 0; i < index; i++)
		{
			*(puglyNubmers + i) = 0;
		}
	}
	*puglyNubmers = 1;
	int nextUglyIndex = 1;
	int *pMultiply2 = puglyNubmers;
	int *pMultiply3 = puglyNubmers;
	int *pMultiply5 = puglyNubmers;
	while (nextUglyIndex < index)
	{
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		puglyNubmers[nextUglyIndex] = min;
		while (*pMultiply2 * 2 <= puglyNubmers[nextUglyIndex])
		{
			++pMultiply2;
		}
		while (*pMultiply3 *3 <= puglyNubmers[nextUglyIndex])
		{
			++pMultiply3;
		}
		while (*pMultiply5 * 5 <=puglyNubmers[nextUglyIndex])
		{
			++pMultiply5;
		}
		++nextUglyIndex;
	}
	int ugly = puglyNubmers[nextUglyIndex-1];
	free(puglyNubmers);
	puglyNubmers = NULL;
	return ugly;

}
int main()
{
	int c = 0;
	scanf("%d", &c);
	int d = GetUglyNumber2(c);
	printf("%d", d);
	system("pause");
	return 0;
}