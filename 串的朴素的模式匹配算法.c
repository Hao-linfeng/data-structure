#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Stress
{
	char* ch;
	int length;
}Stress;

int Index(Stress S, Stress T, int pos);

int main()
{
	int i = 0;
	Stress S;
	Stress T;
	S.ch = "123456789";
	S.length = 9;
	T.ch = "789";
	T.length = 3;
	i=Index(S, T, 6);
	printf("%d\n", i);



	system("pause");
	return 0;
} 

int Index(Stress S, Stress T, int pos)
{
	int i = pos;

	int j = 0;
	while (i <= S.length && j <= T.length)  // 如果i小于S的长度且小于T的长度时循环
	{
		if (S.ch[i] == T.ch[j])
		{
			++i;                            //如果相同后移  匹配其他字符
			++j;
		}
		else                               //如果不匹配 则跳到当前匹配的第一个字符的后面
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j > T.length)                    //如果 j>T.length 说明T字符串匹配完了  i-T.length 就是匹配的位置
		return i - T.length;                                 
	else
		return 0;
}
