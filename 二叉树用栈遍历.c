#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>                            //abeh##i##fj##k##cg#l###    用于测试
#include<stdlib.h>

typedef struct BitNode
{
	char data;
	struct BitNode* lchile;
	struct BitNode* rchild;
}BiTNode, * BiTree;

void CreateBiTree(BiTree *T);     //创建二叉树
void preorderNonrecursion(BiTNode* bt);    //用栈先序遍历
void inorderNonrecursion(BiTNode *bt);      //用栈中序遍历
void postorderNonrecursion(BiTNode *bt);    //用栈后序遍历
 
int main()
{
	BiTree T;
	CreateBiTree(&T);
    preorderNonrecursion(T);
	printf("\n");
	inorderNonrecursion(T);
	printf("\n");
	postorderNonrecursion(T);
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

void preorderNonrecursion(BiTNode* bt)
{
	if (bt != NULL)
	{
		BiTNode* stack[10];    //构建一个栈
		int top = -1;
		BiTNode* p;
		stack[++top] = bt;          //节点进栈
		while (top != -1)
		{
			p = stack[top--];
			printf("%c", p->data);    //一个节点出栈，并将其左右非空节点入栈
			if (p->rchild != NULL)
				stack[++top] = p->rchild;
			if (p->lchile != NULL)
				stack[++top] = p->lchile;
		}
	}
}

void inorderNonrecursion(BiTNode* bt)
{
	if (bt != NULL)
	{
		BiTNode* stack[10];  // 定义栈
		int top = -1;
		BiTNode* p;
		p = bt;
		while (top != -1 || p != NULL)   //如果栈非空 或者节点非空
		{
			while (p != NULL)
			{
				stack[++top] = p;  //如果节点不为空 进栈
				p = p->lchile;     //p指向左节点
			}
			if (top != -1)   //如果栈非空
			{
				p = stack[top--];
				printf("%c",p->data);  //出栈
				p = p->rchild;       //p指向右节点 
			}
		}
	}
}

void postorderNonrecursion(BiTNode* bt)
{
	if (bt != NULL)
	{
		BiTNode* stack1[20]; int top1 = -1;//前序栈
		BiTNode* stack2[20]; int top2 = -1;//前序输出栈
		BiTNode* p = NULL;
		stack1[++top1] = bt;   //根节点进一号栈
		while (top1 != -1)
		{
			p = stack1[top1--];        //节点出一号栈
			stack2[++top2] = p;           //出的节点进二号栈
			if (p->lchile != NULL)
				stack1[++top1] = p->lchile;  //左右节点非空进栈
			if (p->rchild != NULL)
				stack1[++top1] = p->rchild;
		}
		while (top2 != -1)    //输出二号栈
		{
			p = stack2[top2--];
			printf("%c", p->data);
		}
	}
}
