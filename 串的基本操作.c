#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
//#define MAXSIZE 20

typedef struct
{
	char *ch;
	int length;
}Stress;  


int StresCopy(Stress* S, char* ch);      //复制字符串

int StrLength(Stress* S);                //求串的长度

int StrCompare(Stress* S, Stress* P);    //找出大串

int Strlianjie(Stress*S,Stress one , Stress two );    //串的首尾连接

int SubString(Stress *S,Stress one,int pos,int len);   //求子串   one 从 pos开始取len个

int ClearString(Stress* S);                           //清空串


int main()
{
	int L;
	Stress S;               //串的初始化
	Stress one;
	Stress two;
	S.ch = (char*)malloc(sizeof(char) * 3);
	char* ch = "hello world!";
	one.ch = "abcd";
	one.length = 4;
	two.ch = "efgh";
	two.length = 4;
	

	StresCopy(&S,ch);
	L = StrLength(&S);
	

	printf("%s\n%d\n", S.ch,L);
	Strlianjie(&S, one, two);  //串的首尾连接
	printf("%s\n%d", S.ch, L);

	 SubString(&S,one,0,3);   //求子串   one 从 pos开始取len个
	 printf("\n%s\n", S.ch);




	

	system("pause");
	return 0;
}

int StresCopy(Stress* S, char* ch)   //复制串
{
	char *c = ch;
	int len = 0;
	if (S->ch)
		free(S->ch);
	while (*c)
	{
		++len;
		++c;
	}
	if (len == 0)
	{
		S->ch = NULL;
		S->length = 0;
		return 1;
	}
	else
	{
		S->ch = (char*)malloc(sizeof(char)*(len+1));
		if (S->ch == NULL)
			return 0;
		else
		{
			c = ch;
			for (int i = 0; i <= len; ++i, ++c)
				S->ch[i] = *c;
			S->length = len;
			return 1;
		}
	}

}


int StrLength(Stress* S)
{
	return S->length;
}

int StrCompare(Stress* S, Stress* P)    //找出大串
{
	for (int i = 0; i < S->length && i < P->length; i++)
	{
		if (S->ch[i] != P->ch[i])
			return S->ch[i] - P->ch[i];
	}
	return S->length - P->length;
}

int Strlianjie(Stress* S, Stress one, Stress two)   //串的首尾连接
{
	int i = 0;
	int j = 0;
	if (S->ch)
	{
		free(S->ch);
		S->ch = NULL;
	}
	S->ch = (char*)malloc(sizeof(char)*(one.length+two.length+1));
	if (S->ch == NULL)
		return 0;
	while (i < one.length)
	{
		S->ch[i] = one.ch[i];
		++i;
	}
	while (j <= two.length)   //加上=是因为要加上'\0'
	{
		S->ch[i+j] = two.ch[j];
		++j;
	}
	S->length = one.length + two.length;
	return 1;
}


int SubString(Stress* S, Stress one, int pos, int len)   //求子串
{
	if (pos < 0 || pos >= S->length || len<0 || len>S->length - pos)
		return 0;
	if (S->ch)
	{
		free(S->ch);
		S->ch = NULL;
	}
	if (len == 0)
	{
		S->ch = NULL;
		S->length = 0;
		return 1;
	}
	else
	{
		S->ch = (char*)malloc(sizeof(char)*(len+1));
		int i = pos;
		int j = 0;
		while (i < pos + len)
		{
			S->ch[j] = one.ch[i];
			++i;
			++j;
		}
		S->ch[j] = '\0';
		S->length = len;
		return 1;
	}
}

int ClearString(Stress*S)
{
	if (S->ch)
	{
		free(S->ch);
		S->ch = NULL;
	}
	S->length = 0;
	return 1;
}
