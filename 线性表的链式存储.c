#include<stdio.h>
#include<malloc.h>

typedef struct Node                      //定义一个节点  struct 定义一个结构
{                                       
	int data;
	struct Node* next;                   //定义一个指针，指向结构
}Node;
typedef struct Node* LinkList;

void CreateListHead(LinkList *L, int n);       //头部添加

void print(LinkList L);                        //全部打印

int ListInsert(LinkList* L, int i, int e);     //单链表的插入  i为插入的位置  e为插入的数据

int ListDelete(LinkList* L,int i);             //单链表的删除   i为删除的位置

int ListChange(LinkList* L,int i,int e);            //修改数据    i为修改的位置   

int main()
{
	LinkList head;
	CreateListHead(&head,10);
	ListInsert(&head, 5, 99);
	ListDelete(&head,5);
	ListChange(&head, 5, 100);

	print(head);

	system("pause");
	return 0;
}

void CreateListHead(LinkList *L, int n)   //创建一个节点
{
	LinkList p;
	int i;
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = i;
		p->next = (*L)->next;
		(*L)->next = p;
	}

}

void print(LinkList p)   //定义一个指针指向头节点的下一个节点  看是不是NULL  不是的话打印data
{
	LinkList h;        
	h = p->next;
	while (h)
	{
		printf("%d\n", h->data);
		h = h->next;
	}
}

int ListInsert(LinkList* L, int i, int e)
{
	LinkList p,q;
	p = *L;
	int j = 0;
	if (i <= 0)
	{
		print("error\n");
		return 0;
	}
	for (j = 1; j < i; j++)                 //将指针移到要插入的位置
	{
		if (p->next->next)
			p = p->next;
		else
		{
			printf("error");
			return 0;
		}
	}

	q = (LinkList)malloc(sizeof(Node));   //创建一个结构
	q->data = e;                          //赋值
	q->next = p->next;                    //将新节点插入
	p->next = q;
	
	return 1;

}

int ListDelete(LinkList* L, int i)
{
	LinkList p,q;
	p = *L;
	int j = 1;
	if (i <= 0)
	{
		printf("error\n");
		return 0;
	}
	for (j = 1; j < i; j++)
	{
		p = p->next;
		if (!p->next)
		{
			printf("error\n");
			return 0;
		}
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return 1;

}

int ListChange(LinkList* L, int i,int e)
{
	LinkList p;
	p = *L;
	int j = 0;
	if (i <= 0)
		return 0;
	for (j = 0; j < i; j++)
	{
		if (p->next)
			p = p->next;
		else
		{
			printf("error\n");
			return 0;
		}
	}
	p->data = e;
	return 1;
}
