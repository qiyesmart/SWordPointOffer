#include"test.h"
void  Copy(CN *list)
{
	// ��������ÿ����㣬���µĽ������ϵĽ����
	CN *cur = list;
	CN *newNode;
	// cur ֻ�����ϵĽ��
	while (cur != NULL) {
		newNode = CreateNode1(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;

		cur = newNode->next;
	}

	// ���� random �ֶ�
	cur = list;
	while (cur != NULL) {
		newNode = cur->next;
		if (cur->random != NULL) {
			newNode->random = cur->random->next;
		}

		cur = cur->next->next;
	}

	cur = list;
	CN *next, *newNext;
	CN *result = list->next;
	while (cur != NULL) {
		newNode = cur->next;
		next = newNode->next;
		if (next == NULL) {
			newNext = NULL;
		}
		else {
			newNext = next->next;
		}

		cur->next = next;
		newNode->next = newNext;

		cur = next;
	}

	printf("���Ƴɹ�\n");
}

void test()
{
	CN* n1;
	CN* node1=CNInit(&n1);
	CN* n2;
	CN* node2 = CNInit(&n2);
	CN* n3;
	CN* node3 = CNInit(&n3);
	CN* n4;
	CN* node4 = CNInit(&n4);
	

	Copy(node1);
}
int main()
{
	test();
	system("pause");
	return 0;
}