#include<stdio.h>
#include<malloc.h>

typedef struct StackNode
{
	int data;                      //定义节点
	struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;             //定义链栈
	int count;
}LinkStack;

int Push(LinkStack*L,int e);                    //进栈

int Pop(LinkStack* L,int*e);                   //出栈

int main()
{
	int* e;
	LinkStack L;
	e = (int*)malloc(sizeof(int));

	L.top = NULL;
	L.count = 0;

	Push(&L,1);
	Push(&L, 2);
	Push(&L, 3);
	Push(&L, 4);

	Pop(&L,e);
	printf("%d\n", *e);

	Pop(&L, e);
	printf("%d\n", *e);


	system("pause");
	return 0;
}

int Push(LinkStack* L,int e)               //进栈
{
   LinkStackPtr p;
   p = (LinkStackPtr)malloc(sizeof(StackNode));
   p->data = e;

    p->next = L->top;
	L->top = p;

	L->count++;
	return 1;

}

int Pop(LinkStack* L,int *e)                  //出栈
{
	
	LinkStackPtr p;
	
	if (L->count == 0)
	{
		printf("空\n");
		return 0;
	}
	else
	{
		*e = L->top->data;
		//printf("%d\n", *e);
		p = L->top;
		L->top = L->top->next;
		free(p);
		L->count--;
		return 1;
	}
}
