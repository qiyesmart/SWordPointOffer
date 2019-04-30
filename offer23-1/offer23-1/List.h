#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef   int DataType;

typedef struct ListNode{
	DataType data;
	struct  ListNode *next;
} ListNode;



void  ListInit(ListNode **ppfirst)
{
	assert(ppfirst != NULL);
	*ppfirst = NULL;
}

void ListDestory(ListNode **ppfirst)
{
	*ppfirst = NULL;
}
static ListNode *CreateNode(DataType  data)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}