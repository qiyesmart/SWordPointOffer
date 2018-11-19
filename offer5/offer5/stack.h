#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
typedef   int  DataType;

#define MAXSIZE (100)

typedef   struct{
	DataType  array[MAXSIZE];
	int top;//���˸����������廹��size
}Stack;

void   StackInit(Stack *ps)
{
	ps->top = 0;
}

void   StackDestory(Stack *ps)
{
	ps->top = 0;
}

//ջ�����һ��Ԫ��
void   StackPush(Stack *ps, DataType data)
{
	assert(ps->top < MAXSIZE);
	ps->array[ps->top++] = data;

}
//ջ�е���һ��Ԫ��
void   StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;

}

//����ջ��Ԫ��
DataType   StackTop(const  Stack *ps)
{
	assert(ps->top > 0);
	return ps->array[ps->top - 1];
}

//����ջ�Ĵ�С
int  StackSize(const Stack *ps)
{
	return  ps->top;
}
//����ջ�Ƿ�Ϊ��
int StackEmpty(const Stack *ps)
{
	return ps->top == 0 ? 1 : 0;
}