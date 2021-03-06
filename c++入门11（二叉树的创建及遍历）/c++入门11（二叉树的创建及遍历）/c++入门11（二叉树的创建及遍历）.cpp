// c++入门11（二叉树的创建及遍历）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//定义节点的结构数据域，左指针，右指针
/*typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;

}
BiTreeNode, *BiTree;*/ //BiTreeNode为typedef struct node{...}起了一个新的名字
					 //*BiTree的意思是给 struct node*起了个别名，叫BiTree，故BiTree为指向节点的指针。

class SetBiTreeNode
{
private:
	char data;
	SetBiTreeNode *lchild;
	SetBiTreeNode *rchild;
public:
	SetBiTreeNode * root;
	SetBiTreeNode()
	{
		root = NULL;
	}
	SetBiTreeNode* createBiTree();

	void preTraverse(SetBiTreeNode *);
	void midTraverse(SetBiTreeNode *);
	void postTraverse(SetBiTreeNode *);
};
					 //按照前序顺序建立二叉树
SetBiTreeNode* SetBiTreeNode ::createBiTree() //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,目的是让传递进来的指针发生改变
{
	SetBiTreeNode *F=0;
	char c;
	cin >> c;
	if ('#' == c) //当遇到#时，令树的子节点为NULL，从而结束该分支的递归
		return NULL;
	else
	{
		F = new SetBiTreeNode;
		F->data = c;
		F->lchild=createBiTree();//递归创建左子树
		F->rchild=createBiTree();//递归创建右子树
		return F;
	}
}

//前序遍历二叉树并打印
void SetBiTreeNode::preTraverse(SetBiTreeNode *F)
{
	if (F!=NULL)
	{
		cout << F->data << " ";
		preTraverse(F->lchild);
		preTraverse(F->rchild);
	}
}
//中序遍历二叉树并打印
void SetBiTreeNode::midTraverse(SetBiTreeNode *F)
{
	if (F)
	{
		midTraverse(F->lchild);
		cout << F->data << " ";
		midTraverse(F->rchild);
	}
}
//后续遍历二叉树并打印
void SetBiTreeNode::postTraverse(SetBiTreeNode *F)
{
	if (F)
	{
		postTraverse(F->lchild);
		postTraverse(F->rchild);
		cout << F->data << " ";
	}
}

class Queue
{
public:
	char data = NULL;
	Queue *lchild=nullptr;
	Queue *rchild=nullptr;
	Queue *next=nullptr;
public:
	Queue *Q_Push(Queue *temp,int i);
	Queue *Q_Pop(Queue *temp);
};
Queue *Queue::Q_Pop(Queue *temp)
{
	if(temp==nullptr)
		cout << "队列为空" << endl;
	else
		++temp;
	return temp;
}
Queue *Queue::Q_Push(Queue *temp,int i)
{
	Queue *N = new Queue;
	cout << "请输入第"<< i <<"个节点值：" << endl;
	cin >> N->data;
	while (temp->next== nullptr)
	{
		temp->next = N;
	}
	temp = temp->next;
	    
	return N;
}
class QueueBiTree:public Queue
{
private:
	Queue *head=new Queue;
public:
	QueueBiTree() {}
	void CreateQBT();
	void VisitQBT();
	void preTraverseQBT(Queue *);
	void midTraverseQBT(Queue *);
	void postTraverseQBT(Queue *);
	~QueueBiTree()
	{
		delete head;
	}
};
void QueueBiTree::CreateQBT()
{
	int n, i = 0;
	cout << "请键入二叉树节点个数：" << endl;
	cin >> n;
	cout << "请键入根节点值：" << endl;
	cin >> head->data;
	Queue *temp = head;
	while (i < n)
	{
		temp->Q_Pop(temp);
		i++;
		if (i == n)
			temp->lchild = nullptr;
		else
			temp->lchild = temp->Q_Push(temp,i);
		i++;
		if (i == n)
			temp->rchild = nullptr;
		else
			temp->rchild = temp->Q_Push(temp,i);
	}
}
void QueueBiTree::VisitQBT()
{
	while (nullptr!=head)
	{
		cout << head->data <<' ';
		head = head->next;
	}
	cout << endl;
}
void QueueBiTree::preTraverseQBT(Queue *)
{		
	if (head!=nullptr)
	{
		midTraverseQBT(head->lchild);
	    cout << head->data << " ";
		midTraverseQBT(head->rchild);
	}
}
void QueueBiTree::midTraverseQBT(Queue *)
{
	if (head!=nullptr)
	{
		midTraverseQBT(head->lchild);
	    cout << head->data << " ";
		midTraverseQBT(head->rchild);
	}
}
void QueueBiTree::postTraverseQBT(Queue *)
{

	if (head!=nullptr)
	{
		postTraverseQBT(head->lchild);
		postTraverseQBT(head->rchild);
        cout << head->data << " ";

	}
}
int main()
{
	//SetBiTreeNode *T=new SetBiTreeNode;               //声明一个指向二叉树根节点的指针               
	//T=T->createBiTree();
	//cout << "二叉树创建完成！" << endl;
	//cout << "前序遍历二叉树：" << endl;
	//T->preTraverse(T);
	//cout << endl;
	//cout << "中序遍历二叉树：" << endl;
	//T->midTraverse(T);
	//cout << endl;
	//cout << "后序遍历二叉树：" << endl;
	//T->postTraverse(T);
	//return 0;
	QueueBiTree *T=new QueueBiTree;               //声明一个指向二叉树根节点的指针               
	T->CreateQBT();
	cout << "二叉树创建完成！" << endl;
	cout << "前序遍历二叉树：" << endl;
	T->preTraverseQBT(T);
	cout << endl;
	cout << "中序遍历二叉树：" << endl;
	T->midTraverseQBT(T);
	cout << endl;
	cout << "后序遍历二叉树：" << endl;
	T->postTraverseQBT(T);
	return 0;
}
//#include<iostream>
//#include<stdio.h>
//#include<stack>
//#include<queue>
//using namespace std;
//struct binaryTreeNode {
//	int element;
//	binaryTreeNode *leftChild, *rightChild;
//};
//class binaryTree {
//public:
//	binaryTreeNode * root;
//	binaryTree() {
//		root = NULL;
//	}
//	binaryTreeNode* createBinaryTree();
//	void preOrder(binaryTreeNode *);
//	void inOrder(binaryTreeNode *);
//	void postOrder(binaryTreeNode *);
//	void swapChild(binaryTreeNode**);
//	void leverOrder(binaryTreeNode*);
//	void display() {
//		leverOrder(root);
//		cout << endl;
//	}
//	int widthOfTheTree(binaryTreeNode*);
//};
////
//binaryTreeNode* binaryTree::createBinaryTree()
//{
//	binaryTreeNode* current = 0;
//	char val = 0;
//	cin >> val;
//	if (val == '#')
//		return NULL;
//	else
//	{
//		current = new binaryTreeNode;
//		current->element = val;
//		current->leftChild = createBinaryTree();
//		current->rightChild = createBinaryTree();
//		return current;
//	}
//
//}
//void binaryTree::preOrder(binaryTreeNode *temp) {
//	if (temp != NULL)
//	{
//		cout << temp->element << " ";
//		preOrder(temp->leftChild);
//		preOrder(temp->rightChild);
//	}
//}
//void binaryTree::inOrder(binaryTreeNode *temp) {
//	if (temp != NULL)
//	{
//		inOrder(temp->leftChild);
//		cout << temp->element << " ";
//		inOrder(temp->rightChild);
//	}
//}
//void binaryTree::postOrder(binaryTreeNode *temp) {
//	if (temp != NULL)
//	{
//		postOrder(temp->leftChild);
//		postOrder(temp->rightChild);
//		cout << temp->element << " ";
//	}
//}
//void binaryTree::swapChild(binaryTreeNode**p) {
//	binaryTreeNode*temp;
//	if ((*p)) {
//		temp = (*p)->leftChild;
//		(*p)->leftChild = (*p)->rightChild;
//		(*p)->rightChild = temp;
//		swapChild(&((*p)->leftChild));
//		swapChild(&((*p)->rightChild));
//	}
//}
//void binaryTree::leverOrder(binaryTreeNode*t)
//{
//	queue<binaryTreeNode*> q;
//	if (t != NULL)
//		q.push(t);
//	binaryTreeNode *b;
//	while (!q.empty())
//	{
//		b = q.front();
//		cout << b->element << ' ';
//		q.pop();
//		if (b->leftChild)
//			q.push(b->leftChild);
//		if (b->rightChild)
//			q.push(b->rightChild);
//	}
//}
//int binaryTree::widthOfTheTree(binaryTreeNode*p)
//{
//	if (p == NULL)
//		return 0;
//	queue<binaryTreeNode*> q;
//	q.push(p);
//	int width = 1;
//	int curwidth = 1;
//	int nextwidth = 0;
//	while (!q.empty())
//	{
//		while (curwidth != 0)
//		{
//			binaryTreeNode *temp = q.front();
//			q.pop();
//			curwidth--;
//			if (temp->leftChild != NULL)
//			{
//				q.push(temp->leftChild);
//				nextwidth++;
//			}
//			if (temp->rightChild != NULL)
//			{
//				q.push(temp->rightChild);
//				nextwidth++;
//			}
//		}
//		if (nextwidth>width)
//			width = nextwidth;
//		curwidth = nextwidth;
//		nextwidth = 0;
//	}
//	return width;
//	cout << "width=" << width << endl;
//}
//
//void main()
//{
//	binaryTree a;
//	a.createBinaryTree();
//	a.widthOfTheTree(a.root);
//	a.preOrder(a.root);
//	a.display();
//}
