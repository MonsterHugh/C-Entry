// c++入门02（求数组均值）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	int num[] = { 5,9,8,6,11,25 };
	int *p;
	int temp = 0;

	p = num;

	for (int i = 0; i < sizeof(num)/sizeof(int); i++)
	{
		temp += *p;
	}

	cout << "数组的总值为：" << temp << endl;

	temp /= sizeof(num)/sizeof(int);

	cout << "数组的均值为：" << temp << endl;
	system("pause");
	return 0;
}


