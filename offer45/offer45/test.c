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

//β��
void    ListPushBack(ListNode **ppfirst, DataType data)
{
	ListNode *newNode = CreateNode(data);
	//����������ҵ�������һ����������һ�����������������Ϊ�գ�
	if (*ppfirst == NULL)
	{
		*ppfirst = newNode;
		return;
	}
	//ͨ�����
	ListNode *cur = *ppfirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
}

//������ʵ��Լɪ��
ListNode * JosephCycle(ListNode *first, int k)
{
	//��һ���������ɻ�
	ListNode *tail = first;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = first;
	//�ڶ���
	ListNode *cur = first;
	//ѭ������������������ֻʣһ�����
	while (cur->next != cur)
	{
		ListNode *prev = NULL;
		for (int i = 0; i < k - 1; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		//cur����Ҫɾ���Ľ��
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
	//���ʣ����Ǹ���
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