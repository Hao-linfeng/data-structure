#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void print_my(int a[], int n)  //输出数组
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}
/*
void change(int a[], int n)   //这是我写的   我他妈真是个弟弟，写的代码又臭又长
{
	int i = 1;
	int j = 1;
	int y;
	int temp;
	int flag = 0;                 //定义一堆变量，立上flag不做出来不睡觉，编译运行出结果
	while (j<n)                   // 然后看答案  fuck！ 答案怎么才几行   改改改
	{
		y = j;
		if (a[j] != 0)
		{
			temp = a[j];
			y = j - flag;
			while (y)
			{
				a[j] = a[j - 1];
				y--;
			}
			a[flag] = temp;
			flag++;
		}
		j++;
	}
}*/

void change(int a[],int n)   //这是别人写的
{
	int p = 0;
	for(int i=0;i<n;++i)
		if (a[i] != 0)
		{
			if (i!=p)
			{
				a[p] = a[i];
				a[i] = 0;
			}
			++p;
		}
}



int main()
{
	int a[10] = {0,2,3,0,7,0,0,0,0,1};

	change(a, 10);         //非零元素前移（第一个是0）
	print_my(a, 10);

	return 0;
}
