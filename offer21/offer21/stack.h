#pragma once
#include<assert.h>
#include<stdlib.h>
//typedef   
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

//ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ��
//���Ӷ�ΪO(1)
typedef struct{
	Stack  s;//��ͨ��ջ
	Stack  m;//����С���ݵ�ջ
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