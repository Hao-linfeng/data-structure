#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Qlist    //定义结构体
{
	int data[10];
	int top;
}Qlist;

void inlist(Qlist *Q,int n)   //进队列
{
	if (Q->top >= 10)
	{
		printf("满\n");
	}
	else
	{
		Q->top++;
		Q->data[Q->top] = n;
	}
}

void outlist(Qlist *Q,int *e)  //出队列
{
	if (Q->top == -1)
	{
		printf("空\n");
	}
	else
	{
		*e = Q->data[Q->top];
		Q->top--;
	}
}

void fun(Qlist* Q, int y)           //将十进制数转换为二进制存入栈中
{
	int j;
	for (j=0; y > 0; y = y / 2)
	{
		j = y % 2;
		inlist(Q,j);
	}
}

void pri(Qlist *Q)         //输出栈中二进制数
{
	while (Q->top > -1)
	{
		printf("%d", Q->data[Q->top]);
		Q->top--;
	}
}

int main()
{
	int k;
	Qlist* Q;
	Q = (Qlist*)malloc(sizeof(Qlist));
	Q->top = -1;              //初始化栈

	scanf("%d", &k);
	fun(Q, k);
	pri(Q);


	return 0;
}
