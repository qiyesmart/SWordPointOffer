#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef   int DataType;

typedef struct ListNode{
	DataType data;
	struct  ListNode *next;
} ListNode;

//≥ı ºªØ

void  ListInit(ListNode **ppfirst)
{
	assert(ppfirst != NULL);
	*ppfirst = NULL;
}
