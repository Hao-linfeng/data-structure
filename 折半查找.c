#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int find(int a[],int low,int high,int k)
{
	int mid;
	while (low <= high)    //每次循环减半
	{
		mid = (low + high) / 2;
		if (a[mid] == k)
			return mid;
		else if (a[mid] > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main()
{
	int c;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	c=find(a, 0, 10, 7);
	printf("%d", c);
	system("pause");
	return 0;
}
