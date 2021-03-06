#pragma once
#include<assert.h>
#include<stdlib.h>
//typedef   
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

//实现一个栈，要求实现Push(出栈)、Pop(入栈)、Min(返回最小值)的时间
//复杂度为O(1)
typedef struct{
	Stack  s;//普通的栈
	Stack  m;//存最小数据的栈
} MinStack;
void  MinStackInit(MinStack *pms)
{
	StackInit(&pms->m);
	StackInit(&pms->s);
}

void  MinStackDestory(MinStack *pms)
{
	StackDestory(&pms->m);
	StackDestory(&pms->s);
}

void  MinStackPush(MinStack *pms, DataType  data)
{
#if 0    
	StackPush(&pms->s, data);
	if ((StackEmpty(&pms->m) || data < StackTop(&pms->m)))
		StackPush(&pms->m, data);
	else
		StackPush(&pms->m, StackTop(&pms->m));
#endif
	StackPush(&pms->s, data);
	if ((StackEmpty(&pms->m) || data < StackTop(&pms->m)))
		StackPush(&pms->m, data);
}

void  MinStackPop(MinStack *pms)
{
#if 0
	StackPop(&pms->s);
	StackPop(&pms->m);
#endif
	DataType data = StackTop(&pms->s);
	StackPop(&pms->s);
	if (data == StackTop(&pms->m))
	{
		StackPop(&pms->m);
	}
}
DataType MinStackTop(MinStack *pms)
{
	return StackTop(&pms->s);
}
DataType  MinStackMin(MinStack *pms)
{
	return StackTop(&pms->m);
}