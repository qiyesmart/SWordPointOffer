#include"test.h"
//����/��ת������
//�������ú�������һ������ַ
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
	ListNode *cur = first;	// һֱָ��ԭ������ĵ�һ�����
	ListNode *node;
	while (cur != NULL) {
		// ��ԭ����ͷɾ
		node = cur;
		cur = cur->next;

		// ͷ�嵽�������
		node->next = result;
		result = node;
	}

	// �����꣬������ӡ
	ListPrint(result);
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