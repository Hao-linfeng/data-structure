#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct ArcNode    //边
{
	int adjvex;           //该边指向的节点
	struct ArcNode* nexttarc;  //指向下一条边的指针
	int info;                  //边的权值
}ArcNode;

typedef struct
{
	char data;          //顶点信息
	ArcNode* firstarc;   //指向第一条边
}VNode;

typedef struct       //一个邻接表
{
	VNode adjlist[4];  
	int n, e;     //顶点数和边数
}AGraph;

int visit[20] = {0};  //全局数组  记录以访问的节点

void DFS(AGraph* G, int v)  //图的深度遍历 DFS
{
	ArcNode* p;
	visit[v] = 1;
	printf("%d", v);                 //访问节点后  p指向顶点v的第一条边
	p = G->adjlist[v].firstarc;
	while (p != NULL)                //如果p非空继续
	{
		if (visit[p->adjvex] == 0)   //如果p未访问
			DFS(G,p->adjvex);
		p = p->nexttarc;     //p已访问指向下一个
	}
}

void BFS(AGraph* G, int v, int visit[20])//广度优先
{
	ArcNode* p;
	int que[20], front = 0, rear = 0;   //定义队列
	int j;
	printf("%d", v);
	visit[v] = 1;                      //标记
	rear = (rear + 1) % 20;            //循环队列
	que[rear] = v;
	while (front != rear)          //如果队列不空
	{
		front = (front + 1) % 20;   
		j = que[front];                  //取队头并排出
		p = G->adjlist[j].firstarc;
		while (p != NULL)            //如果p不为空循环  并将p的邻居放入队列
		{
			if (visit[p->adjvex] == 0)  
			{
				printf("%d", p->adjvex);
				visit[p->adjvex] = 1;    //将p标记已读
				rear = (rear + 1) % 20;
				que[rear] = p->adjvex;
			}
			p = p->nexttarc;
		}
	}
}

int main()
{ 
	int vv[20] = { 0 };
	AGraph TU;
	ArcNode one, two, thr, fou, five, six, sev;
	one.adjvex = 1;
	two.adjvex = 3;
	thr.adjvex = 4;
	fou.adjvex = 4;
	five.adjvex = 2;
	six.adjvex = 0;
	sev.adjvex = 2;

	TU.n = 4;
	TU.e = 7;
	TU.adjlist[0].data = 0;
	TU.adjlist[0].firstarc = &one;
	one.nexttarc = &two;
	two.nexttarc = &thr;
	thr.nexttarc = NULL;

	TU.adjlist[1].data = 1;
	TU.adjlist[1].firstarc = &fou;
	fou.nexttarc = &five;
	five.nexttarc = NULL;

	TU.adjlist[2].data = 2;
	TU.adjlist[2].firstarc = &six;
	six.nexttarc = NULL;

	TU.adjlist[3].data = 3;
	TU.adjlist[3].firstarc = &sev;
	sev.nexttarc = NULL;

	TU.adjlist[4].firstarc = NULL;

	DFS(&TU,0);
	printf("------------");
	BFS(&TU,0,vv);



	system("pause");
	return 0;
}
