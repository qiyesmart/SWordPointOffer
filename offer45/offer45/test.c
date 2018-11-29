#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"

static ListNode *CreateNode(DataType  data)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//尾插
void    ListPushBack(ListNode **ppfirst, DataType data)
{
	ListNode *newNode = CreateNode(data);
	//特殊情况，找到倒数第一个（至少有一个，特殊情况是链表为空）
	if (*ppfirst == NULL)
	{
		*ppfirst = newNode;
		return;
	}
	//通常情况
	ListNode *cur = *ppfirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
}

//单链表实现约瑟夫环
ListNode * JosephCycle(ListNode *first, int k)
{
	//第一步，链表构成环
	ListNode *tail = first;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = first;
	//第二部
	ListNode *cur = first;
	//循环结束条件是链表中只剩一个结点
	while (cur->next != cur)
	{
		ListNode *prev = NULL;
		for (int i = 0; i < k - 1; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		//cur就是要删除的结点
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	cur->next = NULL;
	return cur;
}

int JosephCycle2(int n, int m)
{
	if (n <1)
	{
		return -1;
	}
	if ( m < 1)
	{
		return -1;
	}
	//最后剩余的那个数
	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}
	return last;
}

void test()
{
	/*ListNode *first;
	ListInit(&first);
	ListPushBack(&first, 0);
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);
	ListNode *p=JosephCycle(first, 3);
	printf("%d", p->data);*/

	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int d = JosephCycle2(n, m);
	printf("%d", d);
}
int main()
{
	test();
	system("pause");
	return 0;
}