#pragma once
#include "Stack.h"
#include <string.h>

int IsBracket(char c)
{
	if (('(' == c || ')' == c) ||
		('[' == c || ']' == c ||
		('{' == c || '}' == c))
		)
	{
		return 1;
	}
	return 0;
}
//¿®∫≈∆•≈‰
int MatchBrackets(const char* pStr)
{
	int i = 0;
	int strLen = 0;
	Stack s;
	StackInit(&s);
	strLen = strlen(pStr);
	if (NULL == pStr)
		return 0;
	for (; i < strLen; ++i)
	{
		if (!IsBracket(pStr[i]))
			continue;
		else
		{
			if ('(' == pStr[i] || '[' == pStr[i] || '{' == pStr[i])
			{
				StackPush(&s, pStr[i]);
			}
			else
			{
				if (StackEmpty(&s))
				{
					printf("”“¿®∫≈±»◊Û¿®∫≈∂‡\n");
					return 0;
				}
				char c=StackTop(&s);
				if ((')' == pStr[i] && '(' == c) ||
					(']' == pStr[i] && '[' == c) ||
					('}' == pStr[i] && '{' == c))
				{
					StackPop(&s);
				}
				else
				{
					printf("◊Û”“¿®∫≈¥Œ–Ú≤ª∆•≈‰\n");
					return 0;
				}
			}
		}
	}
	if (!StackEmpty(&s))
	{
		printf("◊Û¿®∫≈±»”“¿®∫≈∂‡\n");
		return 0;
	}
	printf("¿®∫≈∆•≈‰’˝»∑\n");
	return 1;
}
void TestBracket()
{
	char c1[] = "(())abc{[]()}";
	MatchBrackets(c1);
}