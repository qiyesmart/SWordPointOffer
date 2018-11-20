#include"test.h"
ListNode * FindTailK1(ListNode *first, int k)
{
	ListNode *forward = first;
	ListNode *backward = first;
	while (k--)
	{

			forward = forward->next;
	}
	while (forward != NULL)
	{
		forward = forward->next;
		backward = backward->next;
	}
	return backward;
}
ListNode * FindTailK2(ListNode *first, int k)
{
	ListNode *forward = first;
	ListNode *backward = first;
	//k不为0
	while (k == 0)
	{
		return NULL;
	}
	while (k--)
	{
		//结点数不小于k
		if (forward->next != NULL)
		{
			forward = forward->next;
		}
		else
		{
			return NULL;
		}
	}
	while (forward != NULL)
	{
		forward = forward->next;
		backward = backward->next;

	}

	return backward;
}
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

int  main()
{
	ListNode *first;
	ListInit(&first);

	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);

	
	ListNode *result1 = FindTailK1(first, 3);
	printf("%d\n",result1->data);
	ListNode *result2 = FindTailK2(first, 3);
	printf("%d", result2->data);
	system("pause");
	return 0;
}