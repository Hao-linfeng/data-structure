#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 10
typedef int SelemType;

typedef struct           //定义一个栈
{
	SelemType data[MAXSIZE];
	int top;
}SqStack;

int Push(SqStack*S,int e);       //进栈

int Pop(SqStack*S,int*e);         //出栈


int main()
{
	int *e;
	e = (int*)malloc(sizeof(int));

	SqStack S;
	S.top = -1;

	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);
	Push(&S, 4);
	Push(&S, 5);
	Push(&S, 6);

	Pop(&S,e);
	printf("%d\n", *e);

	Pop(&S, e);
	printf("%d\n", *e);

	Pop(&S, e);
	printf("%d\n", *e);

	Pop(&S, e);
	printf("%d\n", *e);


	system("pause");
	return 0;
}

int Push(SqStack* S, int e)
{
	if (S->top == 9)                 //栈满
	{
		printf("满\n");
		return 0;
	}
	else                    
	{
		S->top++;
		S->data[S->top] = e;
		
		return 1;
	}
}

int Pop(SqStack* S, int* e)
{
	if (S->top == -1)               //栈空
	{
		printf("空\n");
		return 0;
	}
	else
	{
		*e = S->data[(S->top)];
		S->top--;
		return 1;
	}
}

