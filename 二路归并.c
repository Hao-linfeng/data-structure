#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



//将数组A的[L1,R1],[L2,R2]合并为有序区间
void merge(int A[], int L1, int R1, int L2, int R2) {
	int i = L1, j = L2;
	int temp[100], index = 0;
	while (i <= R1 && j <= R2) {
		if (A[i] <= A[j]) {
			temp[index++] = A[i++];
		}
		else {
			temp[index++] = A[j++];
		}
	}
	while (i <= R1) temp[index++] = A[i++];
	while (j <= R2) temp[index++] = A[j++];
	//将temp的值一一赋给A[L1~R2]
	for (int i = 0; i < index; i++) {
		A[L1 + i] = temp[i];
	}
}

//对当前区间进行归并排序
void mergeSort(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, mid + 1, right);
	}
}


int main()
{
	int m = 0;
	int a[10] = { 0,38,65,97,76,13,27,49 ,23,56,};
	mergeSort(a, 1,7);
	for (m = 0; m < 8; m++)
		printf("%d ", a[m]);

	system("pause");
	return 0;
}
