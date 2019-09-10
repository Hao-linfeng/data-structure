#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Qlist    //定义栈
{
	char C[20];
	int top;
}Qlist;

void in(Qlist *Q,char i)    //进栈
{
	if (Q->top > 20)
	{
		printf("满\n");
	}
	else
	{
		Q->top++;
		Q->C[Q->top] = i;
	}
}

void out(Qlist* Q)  //出栈
{
	if (Q->top == -1)
	{
		printf("空");
	}
	else
	{
		Q->top--;
	}
}


int main()
{
	int flag = 0;
	int i = 0;
	char ch[20];
	Qlist* Q1,*Q2,*Q3;
	Q1 = (Qlist*)malloc(sizeof(Qlist)); //大括号
	Q2 = (Qlist*)malloc(sizeof(Qlist)); //中括号
	Q3 = (Qlist*)malloc(sizeof(Qlist)); //小括号
	Q1->top = -1;
	Q2->top = -1;
	Q3->top = -1;
	for (i = 0; i < 20; i++)
	{
		scanf("%c", &ch[i]);
	}
	for (i = 0; i < 20; i++)
	{
		switch (ch[i])         //对数组进行循环
		{
		case '{':
			in(Q1, ch[i]);  break;     //左大括号进Q1



		case '}':
			if (Q1->top == -1)     //右大括号  如Q1为空则不匹配    不为空出栈
			{
				flag = 1;
			}
			else
			{
				out(Q1);
			}
			break;


		case '[':
			in(Q2, ch[i]);  break;


		case ']':
			if (Q2->top == -1)
			{
				flag = 1;
			}
			else
			{
				out(Q2);
			}
			break;

		case '(':
			in(Q3, ch[i]);  break;

		case ')':
			if (Q3->top == -1)
			{
				flag = 1;
			}
			else
			{
				out(Q3);
			}
			break;

		case '\'':              //为‘号循环到下一个’号中间的跳过
			i++;
			while (ch[i] != '\'')
			{
				i++;
			}
			break;

		case '"':
			i++;
			while (ch[i] != '"')
			{
				i++;
			}
			break;
		}
		if (flag == 1)
			break;
	}
	if (Q1->top != -1 || Q2->top != -1 || Q3->top != -1)
		flag = 1;

	if (flag == 1)
	{
		printf("No");
	}
	else 
	{
		printf("yes\n");
	}
	

	return 0;
}
