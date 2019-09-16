#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int n = 0;   //用于递归计数

typedef struct BitNode
{
	char data;
	struct BitNode* lchile, * rchild;
}BiTNode, * BiTree;

void CreateBiTree(BiTree* T);     //创建二叉树

void PreOrderTraverse(BiTree T);  //前序遍历

void InOrderTraverse(BiTree T);   //中序遍历

void OutOrderTraverse(BiTree T);  //后序遍历

void trave(BiTree *p,int k);      // 先序遍历 打印第k个

void level(BiTree *p);            //层序遍历

int main()
{
	BiTree T;
	CreateBiTree(&T); 

	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	OutOrderTraverse(T);

	trave(T, 5);
	printf("\n");
	level(T);
	printf("\n");
	system("pause");
	return 0;
}

void CreateBiTree(BiTree* T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		* T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(0);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchile); //构建左子树
		CreateBiTree(&(*T)->rchild);//构建右子树
	}
}

void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);   //打印节点数据
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

void trave(BiTree p, int k)  //前序遍历 第k个
{
	if (p != NULL)
	{
		++n;                      //主函数已定义
		if (k == n)
		{
			printf("%c",p->data);
			return;
		}
		trave(p->lchile,k);   
		trave(p->rchild, k);
	}
}

void level(BiTree p)
{
	int front, rear;
	BiTree que[10];     //定义一个循环队列 记录要访问的节点
	front = rear = 0;
	BiTree q;
	if (p != NULL)
	{
		rear = (rear + 1) % 10;
		que[rear] = p;                  //根节点入队
		while (front != rear)          //队列不空进行循环
		{
			front = (front + 1) % 10;
			q = que[front];            //出栈
			printf("%c", q->data);
			if (q->lchile != NULL)    //如果有左节点 进栈
			{
				rear = (rear + 1) % 10;
				que[rear] = q->lchile;
			}
			if (q->rchild != NULL)     //如果有右节点 进栈
			{
				rear = (rear + 1) % 10;
				que[rear] = q->rchild;
			}
		}
	}

}
