#include"test.h"

int main()
{
	QueueS  qs;
	QSInit(&qs);
	for (int i = 0; i < 10; i++)
	{
		QSPush(&qs, i);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", QSFront(&qs));
		QSPop(&qs);
	}
	system("pause");
	return 0;
}