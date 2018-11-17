#include"test.h"
//逆序/反转单链表
//返回逆置后的链表第一个结点地址
void ListPrint(ListNode *first)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}
void  ReserseList(ListNode *first)
{
	ListNode *result = NULL;
	ListNode *cur = first;	// 一直指向原来链表的第一个结点
	ListNode *node;
	while (cur != NULL) {
		// 从原链表头删
		node = cur;
		cur = cur->next;

		// 头插到结果链表
		node->next = result;
		result = node;
	}

	// 逆置完，做个打印
	ListPrint(result);
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
int main()
{
	ListNode *list1;
	ListInit(&list1);
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 2);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 4);
	ListPushBack(&list1, 5);
	ListPushBack(&list1, 6);
	ListPushBack(&list1, 7);

	ReserseList(list1);
	system("pause");
	return 0;
}