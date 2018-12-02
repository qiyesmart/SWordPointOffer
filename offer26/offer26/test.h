#pragma  once
#include<stdio.h>
#include<stdlib.h>
typedef struct ComplexNode {
	int data;
	struct ComplexNode *next;
	struct ComplexNode *random;
}	CN;

CN * CreateNode1(int data)
{
	CN *node = (CN *)malloc(sizeof(CN));
	node->data = data;
	node->random = node->next = NULL;

	return node;
}

CN * CNInit()
{
	CN *n1 = CreateNode1(1);
	CN *n2 = CreateNode1(2);
	CN *n3 = CreateNode1(3);
	CN *n4 = CreateNode1(4);

	n1->next = n2; n2->next = n3; n3->next = n4;
	n1->random = n3; n2->random = n1; n3->random = n3;

	return n1;
}