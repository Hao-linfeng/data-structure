#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Sift(int R[], int low, int high)
{
	int i = low, j = 2 * i;                 //R[j]是R[i]的左孩子节点
	int temp = R[i];
	while (j <= high)
	{
		if (j < high && R[j] < R[j + 1])    //如果有孩子较大，则把j指向右孩子
			++j;                            //j变为2*i+1
		if (temp < R[j])
		{
			R[i] = R[j];                    //将R[j]调整到双亲节点上
			i = j;                               //修改i和j的值放入最中位置
			j = 2 * i;
		}
		else
			break;
	}
	R[i] = temp;
}

void heapSort(int R[], int n)
{
	int i;
	int temp;
	for (i = n / 2; i >= 1; --i)              //建立初试堆
	{
		Sift(R,i,n);
	}
	for (i = n; i >= 2; --i)                  //进行n-1次循环，完成堆排序
	{
		temp = R[1];
		R[1] = R[i];    //用于换出根节点的关键字，将其放入最终位置
		R[1] = temp;
		Sift(R,1,i-1);    //在减少一个关键字的无须序列中进行调整
	}
}

int main()
{
	int m = 0;
	int a[10] = { 0,38,65,97,76,13,27,49 };
	heapSort(a, 7);
	for (m = 1; m < 8; m++)
		printf("%d ", a[m]);

	system("pause");
	return 0;
}
