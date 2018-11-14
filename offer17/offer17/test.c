#include"test.h"
//合并两个有序链表，合并后依然有序(升序）
ListNode *MergeOrderedList(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;//结果链表
	ListNode *tail = NULL;//结果链表中的最后一个结点，方便尾插
	ListNode *next;//保存遍历过程中的下一个结点
	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			if (result != NULL)
			{
				//结果链表不为空，直接在最后一个结点上做插入
				//保存链表1的下一个结点，让循环继续
				next = cur1->next;
				//插入过程
				tail->next = cur1;
				cur1->next = NULL;
				//保存新的最后一个结点
				tail = cur1;
				cur1 = next;
			}
			else
			{
				//保存链表1的下一个结点，让循环继续
				next = cur1->next;
				result = cur1;
				cur1->next = NULL;
				//保存新的最后一个结点
				tail = cur1;
				cur1 = next;
			}
		}
		else
		{
			if (result != NULL)
			{
				//结果链表不为空，直接在最后一个结点上做插入
				//保存链表1的下一个结点，让循环继续
				next = cur2->next;
				//插入过程
				tail->next = cur2;
				cur2->next = NULL;
				//保存新的最后一个结点
				tail = cur2;
				cur2 = next;
			}
			else
			{
				//保存链表1的下一个结点，让循环继续
				next = cur2->next;
				result = cur2;
				cur2->next = NULL;
				//保存新的最后一个结点
				tail = cur2;
				cur2 = next;
			}
		}
	}
	//一个链表为空了
	if (cur1 == NULL)
	{
		tail->next = cur2;
	}
	if (cur2 == NULL)
	{
		tail->next = cur1;
	}
	return result;
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
		ListNode *list1 = NULL, *list2 = NULL;
		ListPushBack(&list1, 1);
		ListPushBack(&list1, 1);
		ListPushBack(&list1, 5);



		ListPushBack(&list2, 1);
		ListPushBack(&list2, 1 );
		ListPushBack(&list2, 6);
		ListPushBack(&list2, 7);
		ListPushBack(&list2, 8);
		ListPushBack(&list2, 9);
		ListNode *result = MergeOrderedList(list1, list2);
		ListPrint(result);
		system("pause");
		return 0;
}

