#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Stress
{
	char* ch;
	int length;
}Stress;

int Index(Stress S, Stress T, int pos);   

void get_next(Stress T, int* next);     //计算next数组

int main()
{
	int i = 0;
	Stress S;
	Stress T;
	S.ch = "157838545456789";
	S.length = 15;
	T.ch = "789";
	T.length = 3;
	i = Index(S, T, 0);
	printf("%d\n", i);



	system("pause");
	return 0;
}

int Index(Stress S, Stress T, int pos)
{
	int i = pos;

	int j = 0;
	int next[255];
	get_next(T,next);
	while (i <= S.length && j <= T.length)  // 如果i小于S的长度且小于T的长度时循环
	{
		if (j==0 || S.ch[i] == T.ch[j])
		{
			++i;                            //如果相同后移  匹配其他字符
			++j;
		}
		else                               //如果不匹配 则跳到当前匹配的第一个字符的后面
		{
			j = next[j];
		}
	}
	if (j > T.length)                    //如果 j>T.length 说明T字符串匹配完了  i-T.length 就是匹配的位置
		return i - T.length;
	else
		return 0;
}

void get_next(Stress T, int* next)         
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
		
}
