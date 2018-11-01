#include "Stack.h"

#include <assert.h>

void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (MAX_SIZE == s->_top)
	{
		printf("Stack is flow\n");
	}
	s->_array[s->_top++] = data;
}
void StackPop(Stack* s)
{
	assert(s);
	if(StackEmpty(s))
		return;
	s->_top--;
}

int StackTop(Stack* s)
{
	assert(!StackEmpty(s));
	return s->_array[s->_top];
}
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}
int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_top;
}

void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	printf("%d\n", s._top);
	printf("%d\n", StackSize(&s));

	StackPop(&s);
	printf("%d\n", s._top);
	printf("%d\n", StackSize(&s));
}