#include<stdio.h>
#include<stdlib.h>
//有缺陷的解法
int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}
//解法一

int NumebrOf2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
			count++;
		flag = flag << 1;
	}
	return count;
}
//解法二
int NumberOf3(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	}
	return count;
}
int main()
{
	int n = 9;
	int c=NumberOf1(n);
	printf("%d\n", c);
	int d = NumebrOf2(n);
	printf("%d\n", d);
	int f = NumberOf3(n);
	printf("%d\n", f);
	system("pause");
	return 0;
}