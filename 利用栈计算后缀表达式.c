#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct stack                    //定义栈
{
	int c[10];
	int top;
}stack;

void first(stack *c)                    //栈的初始化
{
	c->top = -1;
}

int jjcc(int a,char op,int b)           //加减乘除
{
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
	if (op == '/')
	{
		if (b == 0)
		{
			printf("error分母不能为零\n");
			return 0;
		}
		else
			return a / b;
	}
	else
	{
		printf("error");
		return 0;
	}
}


int outstack(stack *a)                  // 出栈 并返回
{
	int n;
	n = a->c[a->top];
	a->top--;
	return n;
}

void instack(stack* a,int n)            //进栈
{
	a->top++;
	if ((a->top) > 10)
		printf("满\n");
	else
	{
		a->c[a->top] = n;
	}
}

void figure(char d[], stack* q ,int n)
{
	int i;
	int temp;  //进栈数据
	int f, s;  //出栈运算数据
	for (i = 0; i < n; ++i)
	{
		if (d[i] >= '0' && d[i] <= '9')
		{
			temp = d[i] - '0';
			instack(q, temp);
		}
		if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/')
		{
			f = outstack(q);
			s = outstack(q);
			temp = jjcc(s, d[i], f);
			instack(q, temp);
		}
	}	
}



int main()
{
	char f[9] = { '1','2','3','6','*','+','+','7','/' };
	stack* a;
	a = (stack*)malloc(sizeof(stack));

	first(a);
	figure(f, a, 9);
	printf("%d\n", a->c[a->top]);

	return 0;
}
