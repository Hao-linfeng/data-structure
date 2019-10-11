#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct
{
	int key;
	int low, high;
}indexElem;

int find(int a[], indexElem biao[], int num,int v)  //传入待查找数组 表  数字  与表长
{
	int i = 0;
	int H, R;   //查到的块 范围标记
	while (i < v)
	{
		if (num <= biao[i].key)             //找到块后i记录下来  break
			break;         
		i++;
	}
	H = biao[i].low;
	R = biao[i].high;
	while (H <= R)        //块内循序查找
	{
		if (a[H] == num)   
			return H;
		H++;
	}
	return 0;
}


int main()
{
	int a[16] = { 9,22,12,14,35,42,44,38,48,60,58,47,78,80,77,82 };
	int vv;
	indexElem biao[4];
	biao[0].key = 22;
	biao[0].low = 0;
	biao[0].high = 3;
	biao[1].key = 44;
	biao[1].low = 4;
	biao[1].high = 7;
	biao[2].key = 60;
	biao[2].low = 8;
	biao[2].high = 11;
	biao[3].key = 82;
	biao[3].low = 12;
	biao[3].high = 15;

	vv = find(a, biao, 48, 4);
	printf("%d", vv);

	system("pause");
	return 0;
}
