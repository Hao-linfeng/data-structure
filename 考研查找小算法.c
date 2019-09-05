#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void creatlist(Node* c, int a[], int n)
{
	Node* s;
	int i;

	for (i = 0; i < n; ++i)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = a[i];
		s->next = c->next;
		c->next = s;
	}
}



void print_my_one(int a[], int n)  //输出数组
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void print_my_two(Node *c)
{
	Node* p;
	p = c;
	while (p->next != NULL)
	{
		printf("%d\n",p->next->data);
		p = p->next;
	}

}

int find(Node *c,int m)  //取链表倒数第m个
{
	Node* p,*q;
	p = c;
	q = c;
	while (m-1)
	{
		p = p->next;   //先让一个指针走m-1步
		m--;
	}
	while (p->next!=NULL)  //然后两个一起走直到p指向最后一个
	{
		p = p->next;
		q = q->next;
	}
	printf("\n---------->%d\n", q->data);
	return 0;
}

int main()
{
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Node* c;

	c = (Node*)malloc(sizeof(Node));
	c->next = NULL;
	creatlist(c, a, 10);
	

	find(c,3);
	print_my_two(c, 10);

	return 0;
}
