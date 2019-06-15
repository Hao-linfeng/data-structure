#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 10
typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

int EnQueue(SqQueue* Q, int e)          //进
{
	if (Q->rear + 1 % MAXSIZE == Q->front)
		return 0;
	else 
	{
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MAXSIZE;               //加一取余 实现循环
	}
	return 1;
}

int OutQueue(SqQueue* Q, int* e)      //出
{
	if (Q->front == Q->rear)
		return 0;
	else
	{
		*e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
	}
	return *e;
}

void Print(SqQueue* Q)  //输出
{
	int i,j;
	i = Q->front;
	j = Q->rear;

	while (i != j)
	{
		printf("%d\n", Q->data[i]);
		i = (i + 1) % MAXSIZE;		
	}
}

int main()
{
	int* e;
	e = (int*)malloc(sizeof(int)); 
	SqQueue Q;
	Q.front = 0;
	Q.rear = 0;
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 4);

	OutQueue(&Q, e);
	printf("%d\n", *e);
	OutQueue(&Q, e);
	printf("%d\n", *e);
	OutQueue(&Q, e);
	printf("%d\n", *e);

	EnQueue(&Q, 5);
	EnQueue(&Q, 6);
	EnQueue(&Q, 7);
	EnQueue(&Q, 8);

	EnQueue(&Q, 10);
	EnQueue(&Q, 11);
	EnQueue(&Q, 12);
	EnQueue(&Q, 13);

	Print(&Q);


	system("pause");
	return 0;
}
