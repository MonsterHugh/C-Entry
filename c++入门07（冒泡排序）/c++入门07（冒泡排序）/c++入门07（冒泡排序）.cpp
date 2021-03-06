// c++入门07（冒泡排序）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
using std::setw;

#define random(x) (rand()%x)

int n;
int *p;

void SetNumber()
{
	cout << "请键入随机数组长度：" << endl;
	cin >> n;
	cout << n << "位随机数组为：" << endl;
	p = (int*)malloc(sizeof(int)*n);
	srand((int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		p[i] = random(100);
		cout << setw(5) << p[i] ;
	}
}

void sort()
{
	int a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (p[j] < p[j + 1])
			{
				a = p[j + 1];
				p[j + 1] = p[j];
				p[j] = a;
			}
		}
	}
	cout << "\n排序后数组为：\n";
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << p[i];
	}
	cout << endl;
}

int main()
{
	SetNumber();
	sort();
	system("pause");
    return 0;
}

/*void sort(float a[], int n)
{
	float temp;
	for (int i = 1; i<n; i++)
		for (int j = 0; j<n - i; j++)
			if (a[j]>a[j + 1])
				temp = a[j], a[j] = a[j + 1], a[j + 1] = temp;
}

void main4_6()
{
	float b[8] = { 12.3,5.4,89.6, 37.2, 22.4,56.3,62.1,49.0 };
	cout << "排序前数组b中的元素依次为:\n";
	for (int i = 0; i<8; i++)
		cout << b[i] << '\t';
	cout << '\n';
	sort(b, 8);
	cout << "排序后数组b中的元素依次为:\n";
	for (i = 0; i<8; i++)
		cout << b[i] << '\t';
	cout << '\n';
}*/
