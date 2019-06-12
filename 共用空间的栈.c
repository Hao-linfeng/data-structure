#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 7
typedef int SelemType;

typedef struct           //定义一个栈
{
	SelemType data[MAXSIZE];
	int top1;
	int top2;
}SqStack;

int Push(SqStack* S, int e,int number);         //进栈 e为进栈数据    number为栈编号

int Pop(SqStack* S, int* e,int number);         //出栈 e为返回的出栈数据   


int main()
{
	int* e;
	e = (int*)malloc(sizeof(int));
	SqStack S;
	S.top1 = -1;                    //栈1的底部
	S.top2 = MAXSIZE;               //栈2的底部

	Push(&S, 1, 1);
	Push(&S, 2, 1);
	Push(&S, 3, 1);
	Push(&S, 4, 1);
	Push(&S, 5, 1);
	Push(&S, 10, 2);
	Push(&S, 11, 2);
	Push(&S, 12, 2);           //这个数据是进不了栈的  已满

	Pop(&S,e,1);
	printf("%d\n",*e);

	Pop(&S, e, 2);
	printf("%d\n", *e);
	
	system("pause");
	return 0;
}

int Push(SqStack* S, int e,int number)
{
	if (S->top1 + 1 == S->top2)          //判断栈是否满
	{
		printf("满\n");
		return 0;
	}
	if (number == 1)               // 插入1号栈
	{
		S->top1++;
		S->data[S->top1]=e;
	}
	if (number == 2)                //插入2号栈
	{
		S->top2--;
		S->data[S->top2] = e;
	}

}

int Pop(SqStack* S, int* e,int number)   //同理
{
	if (number == 1)
	{
		if (S->top1 == -1)
		{
			printf("空\n");
			return 0;
		}
		else 
		{
			*e = S->data[S->top1];
			S->top1--;
		}
	}

	if (number == 2)
	{
		if (S->top2 == MAXSIZE)
		{
			printf("空\n");
			return 0;
		}
		else
		{
			*e = S->data[S->top2];
			S->top2++;
		}
	}

	return 1;

}
