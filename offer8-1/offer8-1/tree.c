#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int MaxSolution1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int* product = (int *)malloc((length + 1)*sizeof(int));
	product[0] = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;
	int max = 0;
	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int product2 = product[j] * product[i - j];
			if (max < product2)
			{
				max = product2;
			}
			product[i] = max;
		}
	}
	max = product[length];
	free(product);
	return max;
}
int MaxSolution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int times3 = length / 3;
	if (length - times3 * 3 == 1)
		times3 -= 1;
	int times2 = (length - times3 * 3) / 2;
	return(int)(pow(3, times3))*(int)(pow(2, times2));

}
int main()
{
	int t = 8;
	int s = MaxSolution1(t);
	printf("%d", s);
	system("pause");
	return 0;
}