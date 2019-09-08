#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Node    //链队元素
{
	int data;
	struct Node* next;
}Node;

typedef struct Head   //链队类型
{
	Node* front;
	Node* rear;
}Head;

void first(Head* a)   //链队初始化
{
	a->front = NULL;
	a->rear = NULL;
}

void inQlist(Head *a,int n)     //进队列 n为进队列数据
{
	Node* f;
	f = (Node*)malloc(sizeof(Node));
	f->data = n;
	f->next = NULL;

	if (a->front==NULL || a->rear==NULL)
	{
		a->front = f;
		a->rear = f;
	}
	else
	{
		a->rear->next = f;
		a->rear = f;
	}
}

int outQlist(Head*a)                    //出队列
{
	int n;
	Node* t;
	if (a->front == NULL && a->rear == NULL)   //空
	{
		printf("空\n");
		return -1;
	}
	if (a->front == a->rear)                   //只有一个
	{
		t = a->front;
		n = t->data;
		free(t);
		a->front = NULL;
		a->rear = NULL;
		return n;
	}
	else                                     //两个及其以上
	{
		t = a->front;
		n = t->data;
		a->front = t->next;
		free(t);
		return n;
	}
}


int main()
{
	int i;
	Head* a;
	a = (Head*)malloc(sizeof(Head));

	first(a);
	inQlist(a, 1);
	inQlist(a, 2);
	inQlist(a, 3);

	i = outQlist(a);
	printf("%d\n", i);

	i = outQlist(a);
	printf("%d\n", i);

	i = outQlist(a);
	printf("%d\n", i);



	return 0;
}
