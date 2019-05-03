#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int getMaxValue(int *values, int rows, int cols)
{
	if (values == NULL || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	int **maxValue = (int **)malloc(rows*sizeof(int*));
	for (int i = 0; i < cols; i++)
	{
		 maxValue[i]= (int *)malloc(cols*sizeof(int));
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int left = 0;
			int up = 0;
			if (i>0)
				up = maxValue[i-1][j];
			if (j>0)
				left = maxValue[i][j-1];
			if (up > left)
			{
				maxValue[i][j]= up + values[i*cols + j];
			}
			else
			{
				maxValue[i][j] = left + values[i*cols + j];
			}
			
		}
	}
	int maxValue1 = maxValue[rows -1][cols-1];
	for (int i = 0; i < cols; i++)
	{
		free(maxValue[i]);
	}
	free(maxValue);
	return maxValue1;
}
int main()
{
	int str[16] = { 1, 10, 3, 8, 12, 2, 9, 6, 5, 7, 4, 11, 3, 7, 16, 5 };
	int t = getMaxValue(str, 4, 4);
	printf("%d", t);
	system("pause");
	return 0;
}