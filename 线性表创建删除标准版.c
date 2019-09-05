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

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Node *c;

	c = (Node*)malloc(sizeof(Node));
	c->next = NULL;
	creatlist(c, a, 10);
	findanddel(c, 9);
	printf("%d\n", c->next->next->data);
	
	return 0;
}
