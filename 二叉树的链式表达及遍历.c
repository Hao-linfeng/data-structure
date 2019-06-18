#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct BitNode
{
	char data;
	struct BitNode* lchile, * rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree* T);     //创建二叉树

void PreOrderTraverse(BiTree T);  //前序遍历

void InOrderTraverse(BiTree T);   //中序遍历

void OutOrderTraverse(BiTree T);  //后序遍历

int main()
{

	BiTree T;
	CreateBiTree(&T);

	PreOrderTraverse(T);
	printf("\n");	
	InOrderTraverse(T);	
    printf("\n");
	OutOrderTraverse(T);
	printf("\n");

	system("pause");
	return 0;
}

void CreateBiTree(BiTree* T)
{
	char ch;
	scanf("%c",&ch);
	if (ch == '#')
		* T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(0);
		(*T)->data=ch;
		CreateBiTree(&(*T)->lchile); //构建左子树
		CreateBiTree(&(*T)->rchild);//构建右子树
	}
}

void PreOrderTraverse(BiTree T)    
{
	if (T == NULL)
		return;
	printf("%c",T->data);   //打印节点数据
	PreOrderTraverse(T->lchile);  //左
	PreOrderTraverse(T->rchild);  //右
}

void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchile);  //左
	printf("%c", T->data);   //打印节点数据
	InOrderTraverse(T->rchild);  //右
}

void OutOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	OutOrderTraverse(T->lchile);  //左
	OutOrderTraverse(T->rchild);  //右
	printf("%c", T->data);   //打印节点数据
}
