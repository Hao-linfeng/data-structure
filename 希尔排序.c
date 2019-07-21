#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
    
void ShellSort(int* a, int h)    
{
	int temp,j;
	for (int gap = h / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < h; ++i)
		{
			temp = a[i];
			for (j = i;    j >= gap && a[j - gap] > temp;    j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
}

int main()
{
	int m = 0;
	int a[10] = {1,9,2,8,3,7,4,6,5,0};
	ShellSort(a,10);
	for (m = 0; m < 10; m++)
	{
		printf("%d ", a[m]);
	}

	system("pause");
	return 0;
}
