#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void BubbleSort(int *a,int n)
{
	int i, j, flag;                //i j 用于循环    flag用于判断
	int temp;
	for (i = n - 1; i >= 1; --i)   //由底部向上排序，最小的放在前面
	{
		flag = 0;                  //开始flag为零   它用于记录数组是否已经排序好
		for (j = 1; j <= i; ++j)
		{
			if (a[j - 1] > a[j])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = 1;          
			}
		}
		if (flag == 0)
			return;
	}
}

int main()
{
	int m = 0;
	int a[10] = { 2,1,6,3,8,9,0,4,56,134 };
	BubbleSort(a,10);
	for (m = 0; m < 10; m++)
		printf("%d ", a[m]);
	system("pause");
	return 0;
}
