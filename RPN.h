#pragma once
#include "Stack.h"

typedef enum
{
	DATA,
	ADD,
	SUM,
	MUL,
	DIV
}OPERATOR;

typedef struct Cell
{
	OPERATOR _op;
	DataType _data;
}Cell;
//逆波兰表达式
int CalcRPN(Cell* rpn, int size)
{
	int i = 0;
	Stack s;
	StackInit(&s);

	for (; i < size; ++i)
	{
		if (DATA == rpn[i]._op)
		{
			StackPush(&s,rpn[i]._data);
		}
		else
		{
			int left = 0;
			int right = 0;
			right = StackTop(&s);
			StackPop(&s);
			left = StackTop(&s);
			StackPop(&s);
			switch (rpn[i]._op)
			{
			case ADD:
				StackPush(&s, left + right);
				break;
			case SUM:
				StackPush(&s, left - right);
				break;
			case MUL:
				StackPush(&s, left*right);
				break;
			case DIV:
				if (0 == right)
				{
					printf("分母不能够为零\n");
				}
				StackPush(&s, left / right);
				break;
			default:
				break;
			}
		}
	}
	return StackTop(&s);
}
void TestRPN()
{
	Cell RPN[] = { {DATA,12},{DATA,3},{DATA,4},{ADD,0},{MUL,0},{DATA,6},{SUM,0},{DATA,8},{DATA,2},{DIV,0},{ADD,0} };	
	printf("%d ", CalcRPN(RPN, sizeof(RPN) / sizeof(RPN[0])));
}