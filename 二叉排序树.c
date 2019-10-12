#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct BTNode
{
	int key;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode,*BB;


int BSTInsert(BB* bt, int key)         //二重指针
{
	if (*bt == NULL)
	{
		*bt = (BB)malloc(sizeof(BTNode));  //给指针赋空间
		(*bt)->lchild = NULL;
		(*bt)->rchild = NULL;          //左右分别为空
		(*bt)->key = key;
		return 1;
	}
	else
	{
		if (key == ((*bt)->key))     //如果数已存在 直接返回
			return 0;
		else if (key < (*bt)->key)    //数比此节点的key大   到此节点的左节点继续
			return BSTInsert( &(*bt)->lchild,key);
		else
			return BSTInsert(&(*bt)->rchild, key);  //。。。。。
	}
}




BTNode* BSTSearch(BTNode* bt, int key)
{
	if (bt == NULL)
		return NULL;
	else
	{
		if (bt->key == key)       //递归查找
			return bt;
		else if (key < bt->key)
			return BSTSearch(bt->lchild, key);
		else
			return BSTSearch(bt->rchild,key);
	}
}


int main()
{
	BB t=NULL;
	BB p;
	int a[8] = { 5,4,8,7,9,10,6,3 };
	int i = 7;
	
	while (i--)
	{
		BSTInsert(&t, a[i]);
	}
	p = BSTSearch(t,8);
	printf("%d",p->key);

	system("pause");
	return 0;
}
