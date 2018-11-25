#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

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


//����ջʵ��һ������

typedef  struct QueueStack
{
	Stack   stack1;
	Stack   stack2;
}QueueS;

void  QSInit(QueueS *pqs)
{
	StackInit(&(pqs->stack1));
	StackInit(&(pqs->stack2));
}
void QSPush(QueueS *pqs, DataType data)
{
	//����ѹ��ջ1
	StackPush(&(pqs->stack1), data);
}
void QSPop(QueueS *pqs)
{
	Stack  *p1 = &(pqs->stack1);
	Stack  *p2 = &(pqs->stack2);

	//���ջ2Ϊ�գ���ջ1�����ݵ�����
	if (StackEmpty(&(pqs->stack2)))
	{
		while (!StackEmpty(&(pqs->stack1)))
		{
			DataType data = StackTop(p1);
			StackPush(p2, data);
			StackPop(p1);
		}
	}
	StackPop(p2);
}

DataType   QSFront(QueueS *pqs)
{
	Stack  *p1 = &(pqs->stack1);
	Stack  *p2 = &(pqs->stack2);

	//���ջ2Ϊ�գ���ջ1�����ݵ�����
	if (StackEmpty(&(pqs->stack2)))
	{
		while (!StackEmpty(&(pqs->stack1)))
		{
			DataType data = StackTop(p1);
			StackPush(p2, data);
			StackPop(p1);
		}
	}
	return  StackTop(p2);
}


