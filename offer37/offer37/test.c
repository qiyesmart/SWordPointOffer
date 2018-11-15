#include"test.h"

int GetListLength(ListNode *p)
{
	int Length = 0;
	ListNode *pNode = p;
	while (pNode != NULL)
	{
		++Length;
		pNode = pNode->next;
	}
	return Length;
}
ListNode *   PrintInsertsection(ListNode *list1, ListNode *list2)
{
	int length1 = GetListLength(list1);
	int length2 = GetListLength(list2);
	ListNode *longlist = list1;
	ListNode *shortlist = list2;
	int diflength = length1 - length2;
	if (length1 < length2)
	{
		longlist = list2;
		shortlist = list1;
		diflength = length2 - length1;
	}
	for (int i = 0; i < diflength; i++)
	{
		longlist = longlist->next;
	}
	while ((longlist != shortlist)&&longlist != NULL&&shortlist != NULL)
	{
		
			longlist = longlist->next;
			shortlist = shortlist->next;
	}
	ListNode * common = longlist;
	return common;
}

//创建结点
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
void ListPrint(ListNode *first)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}
int main()
{
	ListNode *p = NULL;
	ListNode *list1 = NULL;
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 2);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 6);
	ListPushBack(&list1, 7);

	for (ListNode *cur = list1; cur != NULL; cur = cur->next)
	{
	     p = cur;
	}
	ListNode *list2 = p;
	ListNode *result=PrintInsertsection(list1, list2);
	ListPrint(result);
	system("pause");
	return 0;
}

