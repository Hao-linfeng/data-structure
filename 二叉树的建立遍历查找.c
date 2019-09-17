#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>                            //abeh##i##fj##k##cg#l###    用于测试
#include<stdlib.h>

int n = 0;   //用于递归计数

typedef struct BitNode
{
	char data;
	struct BitNode* lchile;
	struct BitNode* rchild;
}BiTNode, * BiTree;

typedef struct                   //这是用栈实现树的遍历的一个结构体
{
	BiTree p;                    //节点指针 
	int lon;                       //记录节点的层数
}St;

void CreateBiTree(BiTree* T);     //创建二叉树

void PreOrderTraverse(BiTree T);  //前序遍历

void InOrderTraverse(BiTree T);   //中序遍历

void OutOrderTraverse(BiTree T);  //后序遍历

void trave(BiTree p,int k);      // 先序遍历 打印第k个

void level(BiTree p);            //层序遍历

int maxNode(BiTNode* b);         //找节点最多的层上的节点数

int main()
{
	int i;
	BiTree T;
	CreateBiTree(&T); 
	printf("前序遍历");
	PreOrderTraverse(T);
	printf("\n");

	printf("中序遍历");
	InOrderTraverse(T);
	printf("\n");

	printf("后序遍历");
	OutOrderTraverse(T);

	printf("\n第五个\n");
	trave(T, 5);  
	printf("\n");
	printf("层序遍历");
	level(T);
	printf("\n");

	i = maxNode(T);
	printf("最大成\n%d\n",i);
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

int maxNode(BiTNode* b)
{
	St que[30]; 
	int front, rear;
	int Lon, i, j, n, max;
	front = rear = 0;
	BiTNode* q;
	if (b != NULL)
	{
		++rear;
		que[rear].p = b;              //根节点入栈
		que[rear].lon = 1;
		while (front != rear)
		{
			++front;
			q = que[front].p;          //节点出栈  并赋值
			Lon = que[front].lon;      //Lon记录此父节点的层数
			if (q->lchile != NULL)     //如果刚才的节点有左节点 则左节点入栈
			{
				++rear;
				que[rear].p = q->lchile;
				que[rear].lon = Lon + 1;  //因为是孩子节点 所以在此基础上加一
			}
			if (q->rchild != NULL)
			{
				++rear;
				que[rear].p = q->rchild;
				que[rear].lon = Lon + 1;
			}
		}
		max = 0;
		for (i = 1; i <= Lon; ++i)      //  Lon 层数
		{
			n = 0;           //记录每层个数
			for (j = 1; j <= rear; ++j)   //遍历整个数组  rear是栈顶
			{
				if (que[j].lon == i)
					++n;                     //将i层个数计算出  与max对比
				if (max < n)
					max = n;
			}	
		}
		return max;
	}
	else
		return 0;
}
