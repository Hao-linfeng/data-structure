#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Qlist    //定义顺序队列
{
	int data[10];
	int front;
	int rear;
}Qlist;

void first(Qlist*a)     //初始化
{
	a->front = -1;
	a->rear = -1;
}

void inQlist(Qlist* a, int n)  //进
{
	if (a->front == -1 && a->rear == -1)   //第一次进队列
	{
		a->front = 0;
		a->rear = 0;
		a->data[0] = n;
	}
	else
	{
		a->rear++;
		if (a->rear > 10)
		{
			printf("满\n");
			a->rear--;
		}
		else
		{
			a->data[a->rear] = n;
		}
	}
	
}

int outQlist(Qlist* a)   //出
{
	int n;
	if (a->front > a->rear )  //判断是不是满
	{
		printf("满\n");
		return -1;
	}
	else
	{
		n = a->data[a->front];
		a->front++;
		return n;
	}
}


int main()
{
	int y;
	Qlist* a;
	a = (Qlist*)malloc(sizeof(Qlist));

	first(a);
	inQlist(a, 1);
	inQlist(a, 2);
	inQlist(a, 3);

	y = outQlist(a);
	printf("%d", y);

	y = outQlist(a);
	printf("%d", y);

	y = outQlist(a);
	printf("%d", y);

	y = outQlist(a);
	printf("%d", y);


	return 0;
}
