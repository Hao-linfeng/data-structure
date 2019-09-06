#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int find(int a[], int n)
{
	int i, c, count = 1;
	c = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] == c)
			count++;
		else
		{
			if (count > 0)
				count--;
			else
			{
				c = a[i];
				count = 1;
			}
		}
	}
	if (count > 0)
	{
		for (i = count = 0; i < n; i++)
			if (a[i] == c)
				count++;
	}

	if (count > n / 2)
		return c;
	else
		return -1;
}


int main()
{
	int p;
	int a[10] = { 3,2,3,4,3,2,3,1,3,3 };
	int b[20] = { 1,2,3,4,5,6,7,8,9,1,1,1,1,1,1,1,1,1,1,1 };
	p = find(a, 10);
	printf("%d", p);
	p = find(b, 20);
	printf("====%d", p);
	return 0;

}
