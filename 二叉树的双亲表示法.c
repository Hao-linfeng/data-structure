#include<stdio.h>
#include<malloc.h>
typedef struct PTNode
{
	int data;             //节点数据
	int parent;               //双亲位置
	int firstchile;        //左儿子下标
}PTNode;

typedef struct
{
	PTNode nodes[20];         //节点数组
	int r, n;          //根的位置与节点数
}Ptree;

int AddNode(Ptree *T, int i, int e,  int p,  int first)   
{                  //位置   数据    父节点  大儿子
	if (i >= 20)
		return 0;
	T->nodes[i].data = e;
	T->nodes[i].firstchile = first;
	T->nodes[i].parent = p;
	T->n++;
	return 1;
}

int main()
{
	Ptree *T;
	T = (Ptree*)malloc(sizeof(Ptree));
	T->n = 0;
	T->r = 0;

	AddNode(T,0,0,-1,1);
	AddNode(T,1,1,0,3);
	AddNode(T,2,2,0,4);
	AddNode(T,3,3,1,6);
	AddNode(T,4,4,2,9);          //位置   数据    父节点  大儿子
	AddNode(T,5,5,2,-1);
	AddNode(T,6,6,3,-1);
	AddNode(T,7,7,3,-1);
	AddNode(T,8,8,3,-1);
	AddNode(T,9,9,4,-1);

	
	printf("%d\n", T->nodes[T->nodes[3].parent].data);
	printf("%d,%d\n",T->r,T->n);

	system("pause");
	return 0;
}
