#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 10

typedef struct
{
	int data[MAXSIZE];
	int front;  //头
	int rear;   //尾
}SqQueue;

void InitQueue(SqQueue*Q);             //队列初始化

int ClearQueue(SqQueue*Q);             //清空队列

int EnQueue(SqQueue* Q,int e);         //进队列

int Dequeue(SqQueue *Q,int *e);        //出队列

int NumQueue(SqQueue Q);               //返回队列元素个数

int QueueEmpty(SqQueue *Q);            //判断队列是否为空      


int main()
{
	int* e;
	SqQueue Q;
	e = (int*)malloc(sizeof(int));

	InitQueue(&Q);

	EnQueue(&Q, 1);
	NumQueue(Q);
	EnQueue(&Q, 2);

	Dequeue(&Q, e);
	printf("%d\n",*e);

	Dequeue(&Q,e);
	printf("%d\n",*e);

	system("pause");
	return 0;

}

void InitQueue(SqQueue* Q)   //队列初始化
{
	
	Q->front = 0;
	Q->rear = 0;
}


int ClearQueue(SqQueue* Q)     //清空队列
{
	Q->front = 0;
	Q->rear = 0;
	return 0;
}

int QueueEmpty(SqQueue* Q)      //返回个数
{
	if (Q->front == Q->rear)
		return 0;
	else
		return  1;
}

int EnQueue(SqQueue* Q,int e)    //进队列
{
	if (Q->rear==MAXSIZE-1)
	{
		printf("满\n");
		return 0;
	}
	else
	{
		Q->data[Q->rear]=e;
		Q->rear++;
		return 1;
	}
}

int Dequeue(SqQueue *Q, int* e)  //出队列
{
	if (Q->front == Q->rear)
	{
		printf("满\n");
		return 0;
	}
	else
	{
		*e = Q->data[Q->front];
		Q->front++;
		return 1;
	}
}

int NumQueue(SqQueue Q)   //返回队列个数
{
	int e;
	e = Q.rear - Q.front;
	printf("当前队列个数为%d\n",e);
	return 0;
}
