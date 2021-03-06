// c++入门09（指针创建单链表及其功能的实现）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class CList
{
public:
	CList();
	void TravalLinkList(CList *);
	int GetLength(CList *);
	CList *CreateLinkList();
	CList *CreateLinkList1();
	CList *InsertElemAtHead(CList *);
	CList *InsertElemAtIndex(CList *);
	CList *InsertElemAtEnd(CList *);
	CList *DeleteElemAfHead(CList *);
	CList *DeleteElemAfIndex(CList *);
	CList *DeleteElemAfEnd(CList *);
	CList *EmptyLinkList(CList *);
	void  DeleteLinkList(CList *p);
	void SeachLinkList(CList *);
private:
	int m_iData;
	CList *m_pNext;
};
CList::CList()
{
	m_iData = 0;
	m_pNext = nullptr;
}
CList *CList::CreateLinkList()   //头结点不赋值
{
	int n;
	cout << "请输入单链表净长度：" << endl;
	cin >> n;
	CList *head = new CList;
	head->m_iData = 0;
	head->m_pNext = NULL;
	CList *pnew;
	CList *ptemp;
	ptemp = head;

	for (int i = 0; i < n; i++)
	{
		pnew = new CList();
		cout << "请键入第" << i + 1 << "个节点值：" << endl;
		cin >> pnew->m_iData;
		pnew->m_pNext = NULL;
		ptemp->m_pNext = pnew;
		ptemp = pnew;
	}
	cout << "单链表创建完成" << endl;
	return head;
}
CList *CList::CreateLinkList1()  //头结点赋值
{
	int n;
	cout << "请输入单链表长度：" << endl;
	cin >> n;
	CList *pHead = new CList;//创建新节点
	cout << "请键入头结点值" << endl;
	cin>> pHead->m_iData;
	pHead->m_pNext = NULL;

	CList *pNode, *p;
	p = pHead;

	for (int i = 1; i < n; i++)
	{
		pNode = new CList;
		pNode->m_pNext = NULL;
		cout << "请键入第" << i + 1 << "个节点值：" << endl;
		cin >> pNode->m_iData;
		p->m_pNext = pNode;
		p = pNode;//将新节点设置为当前节点
	}
	cout << "单链表创建完成" << endl;
	return pHead;
}

void CList::TravalLinkList(CList *p)//获取单链表值
{
	cout << "单链表值为：" << endl;
	while (NULL != p->m_pNext)//遍历单链表
	{
		cout << p->m_iData << " ";
		p = p->m_pNext;
	}
	cout << p->m_iData << " ";
	cout << endl;
}
int CList::GetLength(CList *p)//获取单链表长度
{
	CList *M = new CList;
	M = p;
	int i = 1;
	if(nullptr==M)
		cout<< "此单链表长度为：" << i << endl;
	else
	{
		while (NULL != M->m_pNext)//遍历单链表
		{
			M = M->m_pNext;
			i++;
		}
		cout << "此单链表长度为：" << i << endl;
	}
	return i;
}

CList *CList::InsertElemAtHead(CList *p)
{
	CList *N = new CList;
	cout << "请输入插入头部的节点数据：" << endl;
	cin >> N->m_iData;
	N->m_pNext = p;//将新节点插入到链表头部
	cout << "头部节点插入完成" << endl;
	cout << "修改后";
	TravalLinkList(N);
	return N;
}

CList *CList::InsertElemAtIndex(CList *p)
{
	int i = GetLength(p);
	int n;
	cout << "请指定插入节点位置或输入“0”退出：" << endl;
	cin >> n;
	if (0 == n)
		return p;
	if (n > i)
	{
		cout << "指定位置超出范围" << endl;
		return p;
	}
	else
	{
		CList *N = new CList;
		CList *temp = new CList;
		temp = p;
		cout << "请输入插入节点数据：" << endl;
		cin >> N->m_iData;
		for (int j = 1; j < n; j++)
		{
				p = p->m_pNext;
		}
		N->m_pNext = p->m_pNext;
		p->m_pNext = N;//将新节点插入到第N个节点后
		p = temp;
		cout << "节点插入完成" << endl;
		cout << "修改后单链表长度为：" << GetLength(p) << endl;
		cout << "修改后";
		TravalLinkList(p);
		return p;
	}
}

CList *CList::InsertElemAtEnd(CList *p) //在尾部插入节点
{
	CList *N = new CList;
	CList *temp = new CList;
	temp = p;
	N->m_pNext = NULL;
	cout << "请输入插入尾部的节点数据：" << endl;
	cin >> N->m_iData;
	while (NULL != p->m_pNext)//遍历单链表
	{
		p = p->m_pNext;
	}
	p->m_pNext = N;//将新节点插入到链表尾部
	p = temp;
	cout << "尾部节点插入完成" << endl;
	cout << "修改后";
	TravalLinkList(p);
	return p;
}

CList *CList::DeleteElemAfHead(CList *p)
{
	CList *temp = new CList;
	temp = p;
	p = p->m_pNext;//将第二节点取出
	delete temp;
	cout << "头部节点删除完成" << endl;
	cout << "修改后";
	TravalLinkList(p);
	return p;
}

CList *CList::DeleteElemAfIndex(CList *p)
{
	int i = p->GetLength(p);
	int n;
	cout << "请指定删除节点位置或输入“0”退出：" << endl;
	cin >> n;
	if (0 == n)
		return p;
	if (n == 1)
	{
		p = p->DeleteElemAfHead(p);
	    return p;
	}
	if (n == i)
	{
		p = p->DeleteElemAfEnd(p);
	    return p;
	}
	if (n > i)
	{
		cout << "指定位置超出范围" << endl;
		return p;
	}
	else
	{
		CList *N = new CList;
        CList *M = new CList;
		CList *temp = new CList;
		N = p;
		temp = p;
		for (int j = 1; j < n-1; j++)
		{
			p = p->m_pNext;
			N = N->m_pNext;
		}	
		N = N->m_pNext;
		p = N->m_pNext;//将后一节点插入到第N个节点后
		delete N;
		M = temp;
		for (int j = 1; j < n-1; j++)
		{
			temp = temp->m_pNext;
		}
		temp->m_pNext = p;
		cout << "节点删除完成" << endl;
		cout << "修改后单链表长度为：" << GetLength(M) << endl;
		cout << "修改后";
		TravalLinkList(M);
		return temp;
	}
}

CList *CList::DeleteElemAfEnd(CList *p)
{
	CList *temp = new CList;
	CList *M = new CList;
	M = p;
	temp = M;
	while (NULL != p->m_pNext)//寻找链表尾部
	{
		M = p;
		p = p->m_pNext;
	}
	M->m_pNext = NULL;
	delete p;
	cout << "尾部节点删除完成" << endl;
	cout << "修改后";
	TravalLinkList(temp);
	return temp;
}

CList *CList::EmptyLinkList(CList *p)
{
	while (NULL != p->m_pNext)//遍历单链表
	{
		p->m_iData = 0;
		p = p->m_pNext;
	}
	p->m_iData = 0;
	cout << "单链表数据清除完成" << endl;
	return p;
}

void CList::DeleteLinkList(CList *p)
{
	delete p;
	cout << "单链表释放完成" << endl;
}

void CList::SeachLinkList(CList *p)
{
	
	int n,i=1;
	cout << "请输入要查询的数据"<<endl;
	cin >> n;
	if(nullptr==p)
		cout << "链表不存在" << endl;
	else
	{
		while (NULL != p->m_pNext)//遍历单链表
		{
			if(n == p->m_iData)
				cout << "该数据在单链表第" << i << "个节点处" << endl;
			p = p->m_pNext;
			i++;
		}
		cout << "数据不在单链表内" << endl;
	}
}

void HelpText()
{
	printf("链表操作指南：\n");
	printf("\t键入“0”创建头结点为空的单链表；\n");
	printf("\t键入“1”创建头结点赋值的单链表；\n");
	printf("\t键入“2”获取单链表长度；\n");
	printf("\t键入“3”获取单链表内值；\n");
	printf("\t键入“4”向头结点前插入节点；\n");
	printf("\t键入“5”向指定节点后插入节点；\n");
	printf("\t键入“6”向尾结点后插入节点；\n");
	printf("\t键入“7”删除头结点；\n");
	printf("\t键入“8”删除指定结点；\n");
	printf("\t键入“9”删除尾结点；\n");
	printf("\t键入“A”清空单链表数据；\n");
	printf("\t键入“B”释放单链表；\n");
	printf("\t键入“C”查找指定数据所处节点；\n");
	printf("\t键入“q”退出程序\n");
}
int main()
{
	
	HelpText();
	system("color F0");
	CList *A = new CList;

	while (1)
	{
		char n;
		cin >> n;
		switch (n)
		{
		case'0': A = A->CreateLinkList();		break;
		case'1': A = A->CreateLinkList1();		break;
		case'2': A->GetLength(A);		break;
		case'3': A->TravalLinkList(A);		break;
		case'4': A = A->InsertElemAtHead(A);		break;
		case'5': A = A->InsertElemAtIndex(A);		break;
		case'6': A = A->InsertElemAtEnd(A);		break;
		case'7': A = A->DeleteElemAfHead(A);		break;
		case'8': A = A->DeleteElemAfIndex(A);		break;
		case'9': A = A->DeleteElemAfEnd(A);		break;
		case'A': A = A->EmptyLinkList(A);		break;
		case'B': A->DeleteLinkList(A);		break;
		case'C': A->SeachLinkList(A);		break;

		default: 			break;
		}
		if ('q' == n)
			break;
	}
	return 0;
}
//
//C++单链表的操作
//2017 - 12 - 25
//// 单链表.cpp: 定义控制台应用程序的入口点。
////Author:kgvito 
////Date: 2017.12.25
//
//
//#include "stdafx.h"
//#include<iostream>
//using namespace std;
//
//typedef int DataType;
//#define Node ElemType
//#define ERROR NULL
//
////构建一个节点类
//class Node
//{
//public:
//	int data;     //数据域
//	Node * next;  //指针域
//};
//
////构建一个单链表类
//class LinkList
//{
//public:
//	LinkList();                      //构建一个单链表;
//	~LinkList();                  //销毁一个单链表;
//	void CreateLinkList(int n);   //创建一个单链表
//	void TravalLinkList();        //遍历线性表
//	int GetLength();              //获取线性表长度
//	bool IsEmpty();               //判断单链表是否为空
//	ElemType * Find(DataType data); //查找节点
//	void InsertElemAtEnd(DataType data);            //在尾部插入指定的元素
//	void InsertElemAtIndex(DataType data, int n);    //在指定位置插入指定元素
//	void InsertElemAtHead(DataType data);           //在头部插入指定元素
//	void DeleteElemAtEnd();       //在尾部删除元素
//	void DeleteAll();             //删除所有数据
//	void DeleteElemAtPoint(DataType data);     //删除指定的数据
//	void DeleteElemAtHead();      //在头部删除节点
//private:
//	ElemType * head;              //头结点
//};
//
////初始化单链表
//LinkList::LinkList()
//{
//	head = new ElemType;
//	head->data = 0;               //将头结点的数据域定义为0
//	head->next = NULL;            //头结点的下一个定义为NULL
//}
//
////销毁单链表
//LinkList::~LinkList()
//{
//	delete head;                 //删除头结点
//}
//
////创建一个单链表
//void LinkList::CreateLinkList(int n)
//{
//	ElemType *pnew, *ptemp;
//	ptemp = head;
//	if (n < 0) {       //当输入的值有误时，处理异常
//		cout << "输入的节点个数有误" << endl;
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 0; i < n; i++) {        //将值一个一个插入单链表中
//		pnew = new ElemType;
//		cout << "请输入第" << i + 1 << "个值: ";
//		cin >> pnew->data;
//		pnew->next = NULL;          //新节点的下一个地址为NULL
//		ptemp->next = pnew;         //当前结点的下一个地址设为新节点
//		ptemp = pnew;               //将当前结点设为新节点
//	}
//}
//
////遍历单链表
//void LinkList::TravalLinkList()
//{
//	if (head == NULL || head->next == NULL) {
//		cout << "链表为空表" << endl;
//	}
//	ElemType *p = head;                 //另指针指向头结点
//	while (p->next != NULL)        //当指针的下一个地址不为空时，循环输出p的数据域
//	{
//		p = p->next;               //p指向p的下一个地址
//		cout << p->data << " ";
//	}
//}
//
////获取单链表的长度
//int LinkList::GetLength()
//{
//	int count = 0;                  //定义count计数
//	ElemType *p = head->next;           //定义p指向头结点
//	while (p != NULL)                //当指针的下一个地址不为空时，count+1
//	{
//		count++;
//		p = p->next;                //p指向p的下一个地址
//	}
//	return count;                   //返回count的数据
//}
//
////判断单链表是否为空
//bool LinkList::IsEmpty()
//{
//	if (head->next == NULL) {
//		return true;
//	}
//	return false;
//}
//
////查找节点
//ElemType * LinkList::Find(DataType data)
//{
//	ElemType * p = head;
//	if (p == NULL) {                           //当为空表时，报异常
//		cout << "此链表为空链表" << endl;
//		return ERROR;
//	}
//	else
//	{
//		while (p->next != NULL)               //循环每一个节点
//		{
//			if (p->data == data) {
//				return p;                     //返回指针域
//			}
//			p = p->next;
//		}
//		return NULL;                           //未查询到结果
//	}
//}
//
////在尾部插入指定的元素
//void LinkList::InsertElemAtEnd(DataType data)
//{
//	ElemType * newNode = new ElemType;    //定义一个Node结点指针newNode
//	newNode->next = NULL;         //定义newNode的数据域和指针域
//	newNode->data = data;
//	ElemType * p = head;              //定义指针p指向头结点
//	if (head == NULL) {           //当头结点为空时，设置newNode为头结点
//		head = newNode;
//	}
//	else                          //循环知道最后一个节点，将newNode放置在最后
//	{
//		while (p->next != NULL)
//		{
//			p = p->next;
//		}
//		p->next = newNode;
//	}
//}
//
////在指定位置插入指定元素
//void LinkList::InsertElemAtIndex(DataType data, int n)
//{
//	if (n<1 || n>GetLength())                   //输入有误报异常
//		cout << "输入的值错误" << endl;
//	else
//	{
//		ElemType * ptemp = new ElemType;        //创建一个新的节点
//		ptemp->data = data;                     //定义数据域
//		ElemType * p = head;                    //创建一个指针指向头结点
//		int i = 1;
//		while (n > i)                           //遍历到指定的位置
//		{
//			p = p->next;
//			i++;
//		}
//		ptemp->next = p->next;                 //将新节点插入到指定位置
//		p->next = ptemp;
//	}
//}
//
////在头部插入指定元素
//void LinkList::InsertElemAtHead(DataType data)
//{
//	ElemType * newNode = new ElemType;    //定义一个Node结点指针newNode
//	newNode->data = data;
//	ElemType * p = head;              //定义指针p指向头结点
//	if (head == NULL) {           //当头结点为空时，设置newNode为头结点
//		head = newNode;
//	}
//	newNode->next = p->next;          //将新节点插入到指定位置
//	p->next = newNode;
//}
//
////在尾部删除元素
//void LinkList::DeleteElemAtEnd()
//{
//	ElemType * p = head;          //创建一个指针指向头结点
//	ElemType * ptemp = NULL;      //创建一个占位节点
//	if (p->next == NULL) {        //判断链表是否为空
//		cout << "单链表空" << endl;
//	}
//	else
//	{
//		while (p->next != NULL)   //循环到尾部的前一个
//		{
//			ptemp = p;            //将ptemp指向尾部的前一个节点
//			p = p->next;          //p指向最后一个节点
//		}
//		delete p;                //删除尾部节点
//		p = NULL;
//		ptemp->next = NULL;
//	}
//}
//
////删除所有数据
//void LinkList::DeleteAll()
//{
//	ElemType * p = head->next;
//	ElemType * ptemp = new ElemType;
//	while (p != NULL)                    //在头结点的下一个节点逐个删除节点
//	{
//		ptemp = p;
//		p = p->next;
//		head->next = p;
//		ptemp->next = NULL;
//		delete ptemp;
//	}
//	head->next = NULL;                 //头结点的下一个节点指向NULL
//}
//
////删除指定的数据
//void LinkList::DeleteElemAtPoint(DataType data)
//{
//	ElemType * ptemp = Find(data);    //查找到指定数据的节点位置
//	if (ptemp == head->next) {        //判断是不是头结点的下一个节点，如果是就从头部删了它
//		DeleteElemAtHead();
//	}
//	else
//	{
//		ElemType * p = head;          //p指向头结点
//		while (p->next != ptemp)      //p循环到指定位置的前一个节点
//		{
//			p = p->next;
//		}
//		p->next = ptemp->next;         //删除指定位置的节点
//		delete ptemp;
//		ptemp = NULL;
//	}
//
//}
//
////在头部删除节点
//void LinkList::DeleteElemAtHead()
//{
//	ElemType * p = head;
//	if (p == NULL || p->next == NULL) {   //判断是否为空表，报异常
//		cout << "该链表为空表" << endl;
//	}
//	else
//	{
//		ElemType * ptemp = NULL;      //创建一个占位节点
//		p = p->next;
//		ptemp = p->next;              //将头结点的下下个节点指向占位节点
//		delete p;                     //删除头结点的下一个节点
//		p = NULL;
//		head->next = ptemp;           //头结点的指针更换
//	}
//}
//
////测试函数
//int main()
//{
//	LinkList l;
//	int i;
//	cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
//	cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
//	cout << "9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素   0.退出" << endl;
//	do
//	{
//		cout << "请输入要执行的操作: ";
//		cin >> i;
//		switch (i)
//		{
//		case 1:
//			int n;
//			cout << "请输入单链表的长度: ";
//			cin >> n;
//			l.CreateLinkList(n);
//			break;
//		case 2:
//			l.TravalLinkList();
//			break;
//		case 3:
//			cout << "该单链表的长度为" << l.GetLength() << endl;
//			break;
//		case 4:
//			if (l.IsEmpty() == 1)
//				cout << "该单链表是空表" << endl;
//			else
//			{
//				cout << "该单链表不是空表" << endl;
//			}
//			break;
//		case 5:
//			DataType data;
//			cout << "请输入要获取节点的值: ";
//			cin >> data;
//			cout << "该节点的值为" << l.Find(data)->data << endl;
//			break;
//		case 6:
//			DataType endData;
//			cout << "请输入要在尾部插入的值: ";
//			cin >> endData;
//			l.InsertElemAtEnd(endData);
//			break;
//		case 7:
//			DataType pointData;
//			int index;
//			cout << "请输入要插入的数据: ";
//			cin >> pointData;
//			cout << "请输入要插入数据的位置: ";
//			cin >> index;
//			l.InsertElemAtIndex(pointData, index);
//			break;
//		case 8:
//			DataType headData;
//			cout << "请输入要在头部插入的值: ";
//			cin >> headData;
//			l.InsertElemAtHead(headData);
//			break;
//		case 9:
//			l.DeleteElemAtEnd();
//			break;
//		case 10:
//			l.DeleteAll();
//			break;
//		case 11:
//			DataType pointDeleteData;
//			cout << "请输入要删除的数据: ";
//			cin >> pointDeleteData;
//			l.DeleteElemAtPoint(pointDeleteData);
//			break;
//		case 12:
//			l.DeleteElemAtHead();
//			break;
//		default:
//			break;
//		}
//	} while (i != 0);
//
//	system("pause");
//	return 0;
//}