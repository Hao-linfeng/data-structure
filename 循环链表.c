#include<stdio.h>
#include<malloc.h>

typedef struct DuLNode
{
	int data;
	struct DuLNode* prior;  //前驱
	struct DuLNode* next;    //后驱
}DuLNode,*DuLinkList;

int AddList(DuLinkList*L,int i);      //增加节点

int ListDelete(DuLinkList*L,int e);   //删除链表中为e的数据

int ListChange(DuLinkList*L,int i,int e );   //将链表中数据为i 的节点改为e  

int Print(DuLinkList* L);             //打印节点



int main()
{
	DuLinkList head,Head;
	head = (DuLinkList)malloc(sizeof(DuLNode));  //开始时前后指针都指向自己

	head->data = 0;
	head->next = head;
	head->prior = head;
	

	AddList(&head, 1);
	AddList(&head, 2);
	AddList(&head, 3);
	AddList(&head, 4);
	AddList(&head, 5);
	AddList(&head, 6);

	
	ListDelete(&head, 4);
	ListDelete(&head, 5);
	ListDelete(&head, 18);
	ListChange(&head, 2, 100);

	Print(&head);

	system("pause");
	return 0;
}

int AddList(DuLinkList* L, int i)
{
	DuLinkList p, q;
	q = (*L);
	if ((*L)->next == (*L))                 //如果只有一个头节点
	{
		p = (DuLinkList)malloc(sizeof(DuLNode));
		p->data = i;

		q->next = p;
		p->prior = q;
		p->next = q;
		q->prior = p;
		return 1;
	}
	else
	{
		p = (DuLinkList)malloc(sizeof(DuLNode));//如果有多个节点 在头节点后插入
		p->data = i;

		p->next = q->next;
		p->prior = q;

		q->next = p;
		p->next->prior = p;

	}
	return 1;
}

int Print(DuLinkList* L)                     //打印节点数据
{
	DuLinkList q, ji;
	q = (DuLinkList)malloc(sizeof(DuLNode));
	ji = (DuLinkList)malloc(sizeof(DuLNode));

	q->next = (*L);
	ji->next = (*L);

	while(1)
	{	
		printf("%d\n", q->next->data);
		q = q->next;

		if(q->next==ji->next)
			break;
	}
	return 1;
}

int ListDelete(DuLinkList* L, int e)               //删除节点
{
	DuLinkList q,p;
	q = (DuLinkList)malloc(sizeof(DuLNode));        //两个节点 一个用于循环 一个用于标记
	p = (DuLinkList)malloc(sizeof(DuLNode));
	q = (*L);
	p = (*L);

	if (q->next == p)                            //只有一个节点不删
	{
		printf("error\n");
		return 0;
	}
	q = q->next;

	while (q!=p)                  //判断是不是 循环过了一圈
	{
		if (q->data == e)
		{
			q->prior->next = q->next;     //改变指针指向
			q->next->prior = q->prior;
			free(q);                           //free 掉无用节点
			return 1;
		}
		q = q->next;
	}
	printf("NO %d\n",e);
	return 0;
}

int ListChange(DuLinkList* L, int i, int e)    //把节点数据为i的节点 修改为 e
{
	DuLinkList q,k;
	q = (DuLinkList)malloc(sizeof(DuLNode));
	k = (DuLinkList)malloc(sizeof(DuLNode));
	q = (*L);
	k = (*L);

	if (q->next == (*L))
	{
		if (q->data == i)
			q->data = e;
	}

	q = q->next;

	while (q != k)
	{
		if (q->data == i)
		{
			q->data = e;
			return 1;
		}
		q = q->next;
	}

	printf("NO %d\n",i);
	return 0;

}
