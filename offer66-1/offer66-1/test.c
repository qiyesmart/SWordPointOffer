#include<stdio.h>
#include<stdlib.h>
void multiply(int *array1, int length1, int *array2, int length2)
{
	if (length1 == length2&&length2 > 1)
	{
		//C[i]=A[0]xA[1]x...A[i-1]
		array2[0] = 1;
		for (int i = 1; i < length1; ++i)
		{
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		int temp = 1;
		//D[i]=A[i+1]x...A[n-1]
		for (int i = length1 - 2; i >= 0; --i)
		{
			temp *= array1[i + 1];
			//B[i]=C[i]xD[i]
			array2[i] *= temp;
		}
	}
	
}
int main()
{
	int arr1[5] = { 1, 2, 3,4,5 };
	int arr2[5] = { 0 };
	multiply(arr1, 5, arr2, 5);
	/*for (int i = 0; i <5; i++)*/
		printf("%d\n", arr2[0]);
	system("pause");
	return 0;
}