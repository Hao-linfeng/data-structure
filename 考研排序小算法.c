#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void creatlist(Node *c ,int a[], int n)
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

void findanddel(Node *c,int x)
{
	Node* p, * q;
	p = c;
	while (p->next != NULL)
	{
		if (p->next->data == x)
			break;
		p = p->next;
	}
	if (p->next == NULL)
		return 0;
	else
	{
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;
	}
}

void insertElem(int a[], int m, int n)
{
	int i, j;
	int temp;
	for (i = m; i < m + n; ++i)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; --j)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}


void print_my(int a[], int n)  //输出数组
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

int main()
{
	int a[10] = { 1,3,5,7,9,2,4,6,8,10};
	Node *c;

	c = (Node*)malloc(sizeof(Node));
	c->next = NULL;
	creatlist(c, a, 10);

	insertElem(a, 4, 6);
	print_my(a,10);
	
	return 0;
}
