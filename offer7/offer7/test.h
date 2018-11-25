#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef   int  DataType;

#define MAXSIZE (100)

typedef   struct{
	DataType  array[MAXSIZE];
	int top;//起了个别名，含义还是size
}Stack;

void   StackInit(Stack *ps)
{
	ps->top = 0;
}

void   StackDestory(Stack *ps)
{
	ps->top = 0;
}

//栈中入放一个元素
void   StackPush(Stack *ps, DataType data)
{
	assert(ps->top < MAXSIZE);
	ps->array[ps->top++] = data;

}
//栈中弹出一个元素
void   StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;

}

//弹出栈顶元素
DataType   StackTop(const  Stack *ps)
{
	assert(ps->top > 0);
	return ps->array[ps->top - 1];
}

//返回栈的大小
int  StackSize(const Stack *ps)
{
	return  ps->top;
}
//返回栈是否为空
int StackEmpty(const Stack *ps)
{
	return ps->top == 0 ? 1 : 0;
}


//两个栈实现一个队列

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
	//无脑压入栈1
	StackPush(&(pqs->stack1), data);
}
void QSPop(QueueS *pqs)
{
	Stack  *p1 = &(pqs->stack1);
	Stack  *p2 = &(pqs->stack2);

	//如果栈2为空，从栈1将数据倒过来
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

	//如果栈2为空，从栈1将数据倒过来
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


