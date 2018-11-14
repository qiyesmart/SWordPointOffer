#include"test.h"
//�ϲ��������������ϲ�����Ȼ����(����
ListNode *MergeOrderedList(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;//�������
	ListNode *tail = NULL;//��������е����һ����㣬����β��
	ListNode *next;//������������е���һ�����
	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			if (result != NULL)
			{
				//�������Ϊ�գ�ֱ�������һ�������������
				//��������1����һ����㣬��ѭ������
				next = cur1->next;
				//�������
				tail->next = cur1;
				cur1->next = NULL;
				//�����µ����һ�����
				tail = cur1;
				cur1 = next;
			}
			else
			{
				//��������1����һ����㣬��ѭ������
				next = cur1->next;
				result = cur1;
				cur1->next = NULL;
				//�����µ����һ�����
				tail = cur1;
				cur1 = next;
			}
		}
		else
		{
			if (result != NULL)
			{
				//�������Ϊ�գ�ֱ�������һ�������������
				//��������1����һ����㣬��ѭ������
				next = cur2->next;
				//�������
				tail->next = cur2;
				cur2->next = NULL;
				//�����µ����һ�����
				tail = cur2;
				cur2 = next;
			}
			else
			{
				//��������1����һ����㣬��ѭ������
				next = cur2->next;
				result = cur2;
				cur2->next = NULL;
				//�����µ����һ�����
				tail = cur2;
				cur2 = next;
			}
		}
	}
	//һ������Ϊ����
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
//�������
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

