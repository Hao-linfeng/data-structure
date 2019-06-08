#include<stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;                                         //定义数据类型
typedef struct                                                      //定义一个数据结构
{
	ElemType data[MAXSIZE];                               //线性表存储的元素个数
	int length;                                           //线性表当前长度
}SqLite;

int GetElem(SqLite L, int i, ElemType* e);           //查找位于i的元素数据 并返回给e

int ListInsert(SqLite* L, int i, ElemType e);          //插入数据   i之前插

int ListDelete(SqLite* L, int i, ElemType* e);        //删除i位置的数据  并赋值给e 

int add(SqLite* L, int i);                            //尾部增加

void print_my(SqLite L);                              //打印所有数据


int main()
{
	int i = 0;
	int e;

	SqLite L;
	L.length = 0;

	for (i = 0; i < MAXSIZE; i++)
	{
		add(&L, i);
	}
	
	ListDelete(&L,5,&e);
	ListInsert(&L, 5, 99);

	print_my(L);
	printf("%d",e);
	
	system("pause");
	return 0;
}

int GetElem(SqLite L, int i, ElemType* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

int ListInsert(SqLite* L, int i, ElemType e)
{
	int k;   
	if (L->length == MAXSIZE)   //大于最大的存储值返回ERROR
		return ERROR;
	if (i<1 || i> L->length + 1)     //小于1 或 大于当前数据位置返回1
		return ERROR;
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i - 1; k--)   //k赋值为当前线性表最后一个元素的下标
		{
			L->data[k + 1] = L->data[k];             // i-1 为要插入的数据位置的前一个位置的下标
		}                                                             // 将要插入的数据位置后的元素后移
	}
	L->data[i - 1] = e;                                   //空出一个位置 插入新数据
	L->length++;                                         //长度加加
	return OK;
}

int ListDelete(SqLite* L, int i, ElemType* e)   //同上
{
	int k;
	if (L->length==0)
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;
	if (i < L->length)
	{
		*e = L->data[i - 1];
		for (k = i ; k < L->length ; k++)
		{
			L->data[k-1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

int add(SqLite* L, int i)                              //尾部增加
{
	if (L->length >= MAXSIZE)
		return ERROR;
	else
		L->data[L->length] = i;
	L->length++;
	return OK;

}

void print_my(SqLite L)
{
	int count,i;
	i = 0;
	count = L.length;
	while (count)
	{
		printf("%d\n", L.data[i]);
		i++;
		count--;
	}
}
