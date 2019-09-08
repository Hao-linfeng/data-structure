#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct stack
{
	char c[10];
	int top;
}stack;

void first(stack* a)
{
	a->top= -1;
}

int Hlf(stack* a, char k[], int n)         //如果括号匹配的话 top == -1  is True
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (k[i] == '(')                   //遇到左括号加一
		{
			a->top++;
			a->c[a->top] = k[i];
		}
		else if (k[i] == ')')               //右括号减一
		{
			if (a->top < 0)
			{
				printf("不匹配\n");         //如果有右括号而没有左括号 不匹配
				return 0 ;
			}
			if (a->top >= 0)
			{
				a->top--;
			}
		}
	}
	if (a->top == -1)
		printf("匹配\n");
	else
		printf("不匹配\n");
	return 1;
}



int main()
{
	char k[10] = { '(','(',')',')','q','r','c','s','c','c' };
	char l[10] = { '(','(',')',')','(','r','c','s','c','c' };
	char r[10] = { '(','(',')',')','q',')','c','s',')','c' };
	char p[10] = { '(','(',')',')','q','(','c','s',')','c' };
	char t[10] = { ')','(',')',')','q','(','c','s',')','c' };

	stack* a;
	a = (stack*)malloc(sizeof(stack));

	first(a);

	printf("k");
	Hlf(a, k, 10);

	printf("l");
	Hlf(a, l, 10);

	printf("r");
	Hlf(a, r, 10);

	printf("p");
	Hlf(a, p, 10);

	printf("t");
	Hlf(a, t, 10);

	return 0;
}
