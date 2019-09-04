#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void change(int b[],int n ,int m) //这是一个反转函数 b数组的 n到m之间的数据反转
{
	int i, j, temp;
	for (i = n, j = m; i < j; i++, j--)
	{
		temp = b[i];
		b[i] = b[j];
		b[j] = temp;
	}
}

void print_my(int a[],int n)  //输出数组
{
	int i ;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void RcR(int b[],int p,int n)   // 实现b数组向左循环p个单位  左边没有右边冒出来
{
	change(b, 0, p - 1);   //前p个反转
	change(b, p, n);       //后面的反转
	change(b, 0, n);     //整个的反转
}

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	RcR(a, 3, 9);	
	print_my(a, 10);

	return 0;
}
