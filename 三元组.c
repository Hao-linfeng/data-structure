#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void create(int A[][4],int m,int n,int B[][3])
{
	int k = 1;
	int i = 0, j = 0;
	for (i=0;i<m;i++)   //对目标数组行循环
	{
		for (j=0;j<n;++j)   //没一行进行循环
		{
			if (A[i][j] != 0)    //如果不等与0 放入三元组
			{
				B[k][0] = A[i][j];
				B[k][1] = i;
				B[k][2] = j;
				k++;
			}
		}
	}
	B[0][0] = k - 1;    //三元组一行 第一个表示三元组中存储的非零个数  另外两个表示行和列
	B[0][1] = m;
	B[0][2] = n;
}

void print_shan(int B[][3])
{
	int k =1;
	for (int i = 0; i < B[0][1]; ++i)   //对行进行循环
	{
		for (int j = 0; j < B[0][2]; ++j)   //每一行进行循环
		{
			if (i == B[k][1] && j == B[k][2])   //如果  i，j  存储在三元组中的话 打印三元组
			{
				printf("%d", B[k][0]);
				++k;
			}
			else                                  //否则打印0
			{
				printf("%d",0);
			}
		}
		printf("\n");
	}
}

int main()
{
	int B[6][3];
	int A[4][4] = { 
					{0,0,0,1},
					{0,0,3,2},
					{1,0,0,0},
					{0,2,0,0},
	};

	create(A,4,4,B);
	print_shan(B);
	return 0;
}
