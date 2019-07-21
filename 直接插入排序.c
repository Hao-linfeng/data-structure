#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void InsertSort(int *a,int n)                         //就是将待排序的数字插入到已经排序好了的序列中
{
	int i, j;
	int temp;
	for (i = 1; i < n; ++i)
	{
		temp = a[i];   //记录待排数据
		j = i - 1;
		while (j >= 0 && temp < a[j])   //j为要插入的位置
		{
			a[j + 1] = a[j];
			--j;                     //要插入位置后的数字后移
		}
		a[j + 1] = temp;
	}
}

int main()
{
	int m = 0;
	int a[10] = { 1,9,2,8,3,7,4,6,5,0 };
	InsertSort(a,10);
	for (m = 0; m < 10; m++)
	{
		printf("%d ", a[m]);
	}
	system("pause");
	return 0;
}
