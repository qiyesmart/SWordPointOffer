#include"test.h"
void DeleteNode(ListNode **phead, ListNode *pdelete)
{
	assert(phead && pdelete);

	//要删除的不是尾结点
	if (pdelete->next != NULL)
	{
		ListNode *pnext = pdelete->next;
		pdelete->data = pnext->data;
		pdelete->next = pnext->next;
		free(pnext);
		pnext = NULL;
	}
	//删除头结点
	else if (*phead == pdelete)
	{
		free(pdelete);
		pdelete = NULL;
		*phead = NULL;
	}
	//删除尾结点
	else
	{
		ListNode * pNode =* phead;
		while (pNode->next != pdelete)
		{
			pNode = pNode->next;
		}
		pNode->next = NULL;
        free(pdelete);
		pdelete = NULL;
	}
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
ListNode   *ListFind(ListNode *first, DataType data)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next)
	{
		if (data == cur->data)
			return cur;
	}
	return NULL;
}

void ListPrint(ListNode *first)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

int main()
{
	ListNode *first;
	ListInit(&first);

	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);
	ListNode *result = ListFind(first, 1);
	DeleteNode(&first, result);
	ListPrint(first);
	system("pause");
	return 0;
}