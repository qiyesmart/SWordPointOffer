#include "List.h"
//判断链表中是否有环
ListNode * MeetNode(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	ListNode * pSlow = pHead->next;
	ListNode *pFast = pSlow->next;
	while (pFast != NULL&&pSlow != NULL)
	{
		if (pFast == pSlow)
		{
			return pFast;
		}
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != NULL)
		{
			pFast = pFast->next;
		}
	}
	return NULL;

}
ListNode *EntryNode(ListNode * pHead)
{
	ListNode * meetingNode = MeetNode(pHead);
	//如果链表中五环则返回NULL
	if (meetingNode == NULL)
		return NULL;
	//确定环中结点数目
	int nodeLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->next != meetingNode)
	{
		pNode1 = pNode1->next;
		nodeLoop++;
	}
	//先移动pNode1
	pNode1 = pHead;
	for (int i = 0; i < nodeLoop; ++ i)
	{
		pNode1 = pNode1->next;
	}
	//同时移动pNode1和pNode2
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}
//尾插法
void    ListPushBack(ListNode **ppfirst, DataType data)
{
	ListNode *newNode = CreateNode(data);
	if (*ppfirst == NULL)
	{
		*ppfirst = newNode;
		return;
	}
	ListNode *cur = *ppfirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
}
//查找结点
ListNode   *ListFind(ListNode *first, DataType data)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next)
	{
		if (data == cur->data)
			return cur;
	}
	return NULL;
}
//构造有环的链表
void CreateLoop(ListNode **pfirst)
{
	ListNode *str = ListFind(*pfirst, 3);
	ListNode *cur = *pfirst;
	//ListNode *str = cur->next->next;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = str;
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
	CreateLoop(&list1);
	ListNode *m = EntryNode(list1);
	system("pause");
	return 0;
}