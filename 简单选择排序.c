#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void SelectSort(int* a, int h)
{
	int i = 0;
	int j = 1;
	int temp;
	for (i = 0; i < h-1; i++)
	{
		for (j = i + 1; j < h; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int m = 0;
	int a[10] = { 1,2,5,4,6,7,9,0,5,3 };
	SelectSort(a,10);
	for (m = 0; m < 10; m++)
	{
		printf("%d ", a[m]);
	}


	system("pause");
	return 0;
}
