// c++入门13（基于栈实现二叉树的遍历）.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include<stdio.h>
#include<stdlib.h>

#define TREELEN 6

struct NODE {
	NODE* pLeft;
	NODE* pRight;
	char chValue;
};

void ReBuild(char* pPreOrder, char* pInOrder, int nTreeLen, NODE** pRoot) {
	if (pPreOrder == NULL || pInOrder == NULL) {
		return;
	}
	NODE* pTemp = (NODE*)malloc(sizeof(NODE));
	pTemp->chValue = *pPreOrder;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	if (*pRoot == NULL) {
		*pRoot = pTemp;
	}
	if (nTreeLen == 1) {
		return;
	}
	char* pOrgInOrder = pInOrder;
	char* pLeftEnd = pInOrder;
	int nTempLen = 0;
	while (*pPreOrder != *pLeftEnd) {
		if (pPreOrder == NULL || pLeftEnd == NULL) {
			return;
		}
		nTempLen++;
		if (nTempLen > nTreeLen) {
			break;
		}
		pLeftEnd++;
	}
	int nLeftLen = 0;
	nLeftLen = (int)(pLeftEnd - pOrgInOrder);
	int nRightLen = 0;
	nRightLen = nTreeLen - nLeftLen - 1;
	if (nLeftLen > 0) {
		ReBuild(pPreOrder + 1, pInOrder, nLeftLen, &((*pRoot)->pLeft));
	}
	if (nRightLen > 0) {
		ReBuild(pPreOrder + nLeftLen + 1, pInOrder + nLeftLen + 1, nRightLen, &((*pRoot)->pRight));
	}
}

/****************
基于递归实现后序遍历,
*****************/
void PostOrderTraverse(NODE* pRoot) {
	if (pRoot == NULL) {
		return;
	}
	else {
		PostOrderTraverse(pRoot->pLeft);
		PostOrderTraverse(pRoot->pRight);
		printf("%c", pRoot->chValue);
	}
	return;
}

/****************
基于栈实现前序和中序遍历
*****************/
void OrderTraverseByStack(NODE* pRoot) {
	NODE* Stack[1000];
	int top = 0;
	while (top > 0 || pRoot != NULL) {
		for (; pRoot != NULL; pRoot = pRoot->pLeft) {
			Stack[top++] = pRoot;
			//前序遍历
			//printf("%c",pRoot->chValue);
		}
		for (; pRoot == NULL && top > 0; pRoot = pRoot->pRight) {
			pRoot = Stack[--top];
			//中序遍历
			printf("%c", pRoot->chValue);
		}
	}
}

/****************
基于栈实现后序遍历
*****************/
void PostOrderTraverseByStack(NODE* pRoot) {
	NODE *StackA[1000], *StackB[1000];
	int topA = 0, topB = 0;
	while (topA > 0 || pRoot != NULL) {
		for (; pRoot != NULL; pRoot = pRoot->pRight) {
			StackA[topA++] = pRoot;
			StackB[topB++] = pRoot;
		}
		for (; pRoot == NULL && topA > 0; pRoot = pRoot->pLeft) {
			pRoot = StackA[--topA];
		}
	}
	while (topB > 0) {
		printf("%c", StackB[--topB]->chValue);
	}
}

int main() {
	NODE* pRoot = NULL;
	char pre[TREELEN] = { 'a','b','d','e','c','f' };
	char in[TREELEN] = { 'd','b','e','a','f','c' };
	ReBuild(pre, in, TREELEN, &pRoot);
	printf("\n通过栈实现的中序遍历结果：\n");
	OrderTraverseByStack(pRoot);
	printf("\n通过递归实现的后序遍历结果：\n");
	PostOrderTraverse(pRoot);
	printf("\n通过栈实现的后序遍历结果：\n");
	PostOrderTraverseByStack(pRoot);
	getchar();
	return 0;
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
