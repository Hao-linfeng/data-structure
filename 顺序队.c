#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct circulate
{
	int data[10];
	int front;
	int rear;
}circulate;

void first(circulate *Q)  //初始化都指向0
{
	Q->front = 0;
	Q->rear = 0;
}

void incirculate(circulate*Q,int n)    //进队列
{
	if ((Q->rear + 1) % 10 == Q->front)  //判断是不是满  注意有一位是空的不放入值
	{
		printf("满\n");                   
	}
	else 
	{
		Q->rear++;
		Q->rear = (Q->rear) % 10;
		Q->data[Q->rear] = n;
	}
}

void outcirculate(circulate* Q,int *b)  //出队列
{
	if (Q->front == Q->rear)
	{
		printf("空");
		*b = -1;
	}
	else
	{
		Q->front++;            //front指向的节点是不存值的 要加一
		*b = Q->data[Q->front];
		
	}

}


int main()
{
	int s;
	
	circulate* Q;
	Q = (circulate*)malloc(sizeof(circulate));

	first(Q);
	incirculate(Q, 1);
	incirculate(Q, 2);
	incirculate(Q, 3);
	incirculate(Q, 4);
	incirculate(Q, 5);
	incirculate(Q, 1);
	incirculate(Q, 2);
	incirculate(Q, 3);
	incirculate(Q, 4);
	incirculate(Q, 5);
	
	outcirculate(Q, &s);
	printf("%d\n",s);
	outcirculate(Q, &s);
	printf("%d\n", s);
	outcirculate(Q, &s);
	printf("%d\n", s);
	outcirculate(Q, &s);
	printf("%d\n", s);
	outcirculate(Q, &s);
	printf("%d\n", s);
	outcirculate(Q, &s);
	printf("%d\n", s);

	outcirculate(Q, &s);
	printf("%d\n", s);
	outcirculate(Q, &s);
	printf("%d\n", s);
	outcirculate(Q, &s);
	printf("%d\n", s);
	outcirculate(Q, &s);
	printf("%d\n", s);


	return 0;
}
