#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct OLNode                      //这是一个普通节点
{
	int row, col;              //行 列
	struct OLNode* right, * down;  //指向右边和下边的节点
	int val;
}OLNode;

typedef struct
{
	OLNode* rhead;    //   这里不知道为什么必须分开写，如果放在一起的话 就会内存访问冲突 但语法和逻辑是没有错的？？？？编译器BUG ???????
	OLNode* chead;    //指向两头的数组节点
	int m, n, k;   //矩阵的行数 列数 和 非零个数
}CrossList;

int createcrossListmat(int A[][4], int m, int n, CrossList *M)
{
	
	for (int i = 0; i < m; ++i)
	{
		M->chead[i].right = NULL;
		M->chead[i].down = NULL;
	}
	for (int i = 0; i < n; ++i)
	{
		M->chead[i].right = NULL;
		M->chead[i].right = NULL;
	}
	OLNode* temp_c[4];       //列链表辅助指针数组
	for (int j = 0; j < n; ++j)
	{
		temp_c[j] = &(M->rhead[j]);
	}
	for (int i = 0; i < m; ++i)        //行循环
	{
		OLNode* r=& (M->chead[i]);                   // 如果每行有几个非零元素时 此指针将其连接在一起
		for (int j = 0; j < n; ++j)    //列循环
		{
			if (A[i][j] != 0)
			{
				OLNode* p;
				p= (OLNode*)malloc(sizeof(OLNode));	   //  // 如果每列有几个非零元素时 此指针将其连接在一起
				p->row = i;
				p->col = j;			
				p->val = A[i][j];                       //节点赋值
				p->down = NULL;
				p->right = NULL;

				r->right = p;                          //指针进行移动
				r = p;
				temp_c[j]->down = p;                      
				temp_c[j] = p;
			}
		}
	}
	return 1;
}

int main()
{
	CrossList* M;
	int A[4][4] = {
					{0,0,0,1},
					{0,0,3,2},
					{1,0,0,0},
					{0,2,0,0},
	};

	M = (CrossList*)malloc(sizeof(CrossList));
	

	M->rhead = (OLNode*)malloc(sizeof(OLNode) * 4);
	M->chead = (OLNode*)malloc(sizeof(OLNode) * 4);
	M->m = 4;
	M->n = 4;
	M->k = 5;

	createcrossListmat(A, 4, 4, M);

	printf("%d", M->rhead[3].down->down->val);


 	return 0;
}
