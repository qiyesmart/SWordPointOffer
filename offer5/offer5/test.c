#include"list.h"
#include"stack.h"
//�����ӡһ������
//����һ
void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;//Ҫ��ӡ�ĺ�һ�����
	while (end != first)
	{
		//ÿ�δӵ�һ�������ǰ��
		ListNode *cur = first;
		//�ҵ�Ҫ��ӡ�Ľ��
		while (cur->next != end)
		{
			cur = cur->next;
		}
		//Ҫ��ӡ�Ľڵ�
		printf("%d", cur->data);
		end = cur;
	}
}
//���������ݹ���⣩
void PrintReserveRecursion(ListNode *first)
{
	if (first->next == NULL)
	{
		printf("%d", first->data);
	}
	else
	{
		PrintReserveRecursion(first->next);
		//�����У�����first������н�㶼�Ѿ������ӡ
		printf("%d", first->data);
	}
}
//��ջʵ��
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