// c++入门05（指针创建单链表）.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct Node {        //链表结构体
	ElemType data;
	struct Node * next;
} Node;

typedef struct Node* Link;    //定义链表指针结构类型



							  //头结点Link的存在是因为方便同一管理和操作数据。


							  /***********************
							  　　　　头插法创表
								  输入：链表指针，初始化个数
								  输出：状态码
								  功能：头插法创建链表
								  ************************/
Status createHead(Link *L, int num) {

	srand(time(0));

	Link link = *L;           //Link L  表示声明一个单链表结构体的指针
	Link n;                   //Link *L 表示声明一个存放单链表结构体指针的指针

	link->data = 0;
	link->next = NULL;

	int i;

	for (i = 0; i<num; i++) {
		n = (Link)malloc(sizeof(Node));
		n->data = rand() % 100 + 1;
		n->next = link->next;
		link->next = n;
	}

	return OK;
}


/***********************
　　　　　尾插法创表
	 输入：链表指针，初始化个数
	 输出：状态码
	 功能：尾插法创建链表
	 ************************/
Status createTail(Link * L, int num) {

	Link tmp, n, link;
	srand(time(0));

	link = *L;
	link->data = 0;
	link->next = NULL;

	tmp = link;

	int i;
	for (i = 0; i<num; i++) {
		n = (Link)malloc(sizeof(Node));
		n->data = rand() % 100 + 1;
		n->next = tmp->next;
		tmp->next = n;
		tmp = tmp->next;
	}

	return OK;
}

/***********************
　　　　　插入节点
	 输入：链表指针，插入位置，插入值
	 输出：状态码
	 功能：在指定的位置上插入指定的值
	 ************************/
Status insertLink(Link * L, int index, ElemType e) {

	index--;
	Link n, tmp = *L;

	int i = 0;
	while (tmp && i<index) {
		tmp = tmp->next;
		i++;
	}

	if (!tmp || i>index) {
		printf("overflow\n");
		return OVERFLOW;
	}

	n = (Link)malloc(sizeof(Node));
	n->data = e;
	n->next = tmp->next;
	tmp->next = n;
	return OK;
}

/***********************
　　　　　删除节点
	 输入：链表指针，删除位置
	 输出：状态码
	 功能：在指定的位置上删除指定的值
	 ************************/

Status deleteLink(Link *L, int index, ElemType *e) {

	index--;
	Link net, tmp = *L;

	int i = 0;
	while (tmp && i<index) {
		tmp = tmp->next;
		i++;
	}

	if (!tmp || i>index) {
		printf("overflow\n");
		return OVERFLOW;
	}

	net = tmp->next;
	tmp->next = net->next;
	free(net);
	return OK;
}

/***********************
　　　　　读取数据
	 输入：链表指针，读取位置，存储指针
	 输出：状态码
	 功能：获取指定位置的值赋予给存储指针
	 ************************/
Status getValue(Link L, int index, ElemType* e) {

	int i = 0;
	index--;
	L = L->next; //ignore head node
	while (L && i<index) {
		L = L->next;
		i++;
	}

	if (!L || i>index) {
		printf("index is valid\n");
		return ERROR;
	}

	*e = L->data;
	return OK;
}

/***********************
　　　　　释放链表
	 输入：链表指针
	 输出：状态码
	 功能：将链表的空间全部释放
	 ************************/
Status freeLink(Link*L) {
	Link p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}

	(*L)->next = NULL;
	return OK;
}

/***********************
　　　　　打印链表
	 输入：链表指针
	 输出：状态码
	 功能：将链表的值一一打印出来
	 ************************/
Status printLink(Link L) {
	Link p = L;

	if (p->next == NULL) {
		printf("link is empty\n");
		return OK;
	}

	int i = 1;
	while (p->next) {
		p = p->next;            //忽略头节点
		printf("[%d] ", p->data);
		if (i % 10 == 0)printf("\n");
		i++;
	}
	printf("\n");
	return OK;
}


/***********************
　　　　　计算个数
	 输入：链表指针，目标值
	 输出：(int)个数结果
	 功能：计算链表中指定的目标值的个数
	 ************************/
int getCount(Link L, ElemType x) {
	int count = 0;
	while (L->next) {
		L = L->next;
		if (L->data == x)count++;
	}
	return count;
}


int main() {
	int index, value, num = 50;
	Link L = (Link)malloc(sizeof(Node));
	createTail(&L, num);
	printLink(L);

	//insert
	printf("enter index:");
	scanf("%d", &index);
	printf("enter value:");
	scanf("%d", &value);
	insertLink(&L, index, value);
	printLink(L);

	//delete
	printf("enter index:");
	scanf("%d", &index);
	deleteLink(&L, index, &value);
	printLink(L);

	//getvalue
	printf("enter index:");
	scanf("%d", &index);
	getValue(L, index, &value);
	printf("value is %d\n", value);

	//getCount
	printf("enter value:");
	scanf("%d", &value);
	int c = getCount(L, value);
	printf("count is %d\n", c);

	//freeLink
	freeLink(&L);
	return OK;
}

