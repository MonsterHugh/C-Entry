// c++入门04（转义字符操作）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	char a[] = "Hello";
	char b[] = "C++";
	cout << a << "\t" << b << endl;
	cout << a << "\n" << b << endl;
	cout << a << "\v" << b << endl;
	cout << a << "\b" << b << endl;
	cout << a << "\r" << b << endl;
	cout << a << "\\" << b << endl;
	cout << a << "\'" << b << endl;
	cout << a << "\"" << b << endl;
	cout << a << "\109" << b << endl;
	cout << a << "\x33" << b << endl;

	system("pause");
	return 0;
}


