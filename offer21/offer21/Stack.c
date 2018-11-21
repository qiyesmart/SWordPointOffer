#include"stack.h"
#include<stdio.h>
void   test1()
{
	MinStack  qs;
	MinStackInit(&qs);
	for (int i = 0; i < 10; i++)
	{
		MinStackPush(&qs, i);
	}
	printf("%d\n", MinStackMin(&qs));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", MinStackTop(&qs));
		MinStackPop(&qs);
	}
}
int main()
{
	test1();
	system("pause");
	return 0;
}