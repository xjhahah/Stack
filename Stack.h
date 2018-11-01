#pragma once

#include <stdio.h>

#define MAX_SIZE 10
typedef int DataType;
typedef struct Stack
{
	DataType _array[MAX_SIZE];
	DataType _top;  //ջ����ЧԪ�صĸ�����ջ��Ԫ��
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, DataType data);
void StackPop(Stack* s);

int StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);
void TestStack();