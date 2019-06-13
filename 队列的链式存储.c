#include<stdio.h>
#include<malloc.h>

typedef struct Qnode
{
	int data;
	struct Qnode* next;                //定义节点
}Qnode,*QueuePtr;

typedef struct
{
	QueuePtr front, rear;              //定义队列的链表结构 
}LinkQueue;  //头    尾

void InitQueue(LinkQueue*Q);             //队列初始化

void DeteleQueue(LinkQueue* Q);          //队列销毁    ???销毁是free()掉节点   而清空是请空节点中的数据

int EnQueue(LinkQueue*Q,int i);          //进队列

int OutQueue(LinkQueue*Q,int*e);         //出队列     

int main()
{
	int* e;
	e = (int*)malloc(sizeof(int));
	LinkQueue Q;

	InitQueue(&Q);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);

	OutQueue(&Q, e);
	printf("%d\n",*e);

	OutQueue(&Q, e);
	printf("%d\n", *e);

	OutQueue(&Q, e);
	printf("%d\n", *e);


	system("pause");
	return 0;
}

void InitQueue(LinkQueue* Q)
{
	QueuePtr head;
	head = (QueuePtr)malloc(sizeof(Qnode));
	Q->front = head;
	Q->rear = head;
	head->next = NULL;
}

void DeteleQueue(LinkQueue* Q)
{
	QueuePtr p;
	while (Q->front->next != NULL)
	{
		p = Q->front->next;
		Q->front = p->next;
		free(p);
	}
}

int EnQueue(LinkQueue* Q, int i)
{
	QueuePtr qq;
	qq = (QueuePtr)malloc(sizeof(Qnode));
	qq->data = i;
	qq->next = NULL;

	Q->rear->next = qq;
	Q->rear = qq;
	return 1;
}

int OutQueue(LinkQueue* Q, int* e)
{
	QueuePtr qq;
	
	if (Q->front->next != NULL)
	{
		qq = Q->front->next;
		*e = qq->data;
		Q->front ->next= qq->next;
		free(qq);
		return 1;
	}
	else
	{
		printf("空\n");
		return 0;
	}
}
