#include"list.h"
#include"stack.h"
//逆向打印一个链表
//方法一
void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;//要打印的后一个结点
	while (end != first)
	{
		//每次从第一个结点往前找
		ListNode *cur = first;
		//找到要打印的结点
		while (cur->next != end)
		{
			cur = cur->next;
		}
		//要打印的节点
		printf("%d", cur->data);
		end = cur;
	}
}
//方法二（递归求解）
void PrintReserveRecursion(ListNode *first)
{
	if (first->next == NULL)
	{
		printf("%d", first->data);
	}
	else
	{
		PrintReserveRecursion(first->next);
		//链表中，除了first外的所有结点都已经逆序打印
		printf("%d", first->data);
	}
}
//用栈实现
void PrintReverseStack(ListNode *first)
{
	Stack stack;
	StackInit(&stack);
	ListNode *phead = first;
	while (phead != NULL)
	{
		StackPush(&stack, phead->data);
		phead = phead->next;
	}
	while (!StackEmpty(&stack))
	{
		DataType t = 0;
		t= StackTop(&stack);
		printf("%d",t);
		StackPop(&stack);
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
int main()
{
	ListNode *first;
	ListInit(&first);

	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);

	PrintReverse(first);
	printf("\n");
	PrintReserveRecursion(first);
	PrintReverseStack(first);
	system("pause");
	return 0;
}