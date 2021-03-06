// c++入门14（基于队列实现二叉树的创建and基于栈遍历二叉树）.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct bitree
{
	int data;
	struct bitree *lchild, *rchild;
}BiTNode;

//////////////函数声明 
BiTNode* CreateBiTree(int *, int);
void PreOderTraverse(BiTNode *);
void DestoryBiTree(BiTNode *);

int main()
{
	BiTNode *t;

	int a[10] = { 1,4,6,7,2,5,3,9,8 };                 //树中结点的数据 

	t = CreateBiTree(a, 10);

	PreOderTraverse(t);

	//DestoryBiTree(t);

	return 0;
}

///////////////////创建二叉树
BiTNode* CreateBiTree(int *a, int n)
{
	BiTNode *root=new BiTNode, *p;
	BiTNode *bitQueue[11];                        //定义一个队列用来存放完全二叉树
	int front = 1, rear = 1;                          //初始化队列

////////////////////////////////////////////////生成结点并入队 
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == 0)
			p = NULL;
		else
		{
			p = (BiTNode *)malloc(sizeof(BiTNode));
			p->data = *(a + i);
			p->lchild = p->rchild = NULL;
		}
		bitQueue[rear++] = p;                    //p结点入队,队尾指针加 1
		if (i == 0) root = p;                       //初始化根节点
	}
	/////////////////////////////////////////////找出结点间的父子关系 
	while (front != rear)                         //如果队列不为空                               
	{
		p = bitQueue[front];                    //当前要找关系的结点 
		if (p != NULL)
		{
			if (2 * front <= n)    p->lchild = bitQueue[2 * front];
			//根据完全二叉树性质，如果2i<n,(n为该二叉树中总结点个数),则该结点有左孩子为2i
			if (2 * front + 1 <= n)  p->rchild = bitQueue[2 * front + 1];
			//如果2i<n,(n为该二叉树中总结点个数),则该结点有左孩子为2i+1
		}
		front++;                               //队头指针加 1，指向下一个结点
	}

	return root;
}

//////////////////前序遍历
void PreOderTraverse(BiTNode *t)
{
	if (t)                   //如果树不为空
	{
		printf("%d ", t->data);
		PreOderTraverse(t->lchild);
		PreOderTraverse(t->rchild);
	}
}

//////////////////销毁二叉树
void DestoryBiTree(BiTNode *t)
{
	if (t)
	{
		if (t->lchild)
			DestoryBiTree(t->lchild);
		if (t->rchild)
			DestoryBiTree(t->rchild);
		free(t);
		t = NULL;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
