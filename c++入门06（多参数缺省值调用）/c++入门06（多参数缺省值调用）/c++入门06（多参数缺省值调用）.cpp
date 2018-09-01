// c++入门06（多参数缺省值调用）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;

class F
{
//private:
//	int _i;
public:
	int _i;
	F(int i)
	{
	    _i = i;
		cout << _i << endl;
		_i = _i * _i;
		/*return _i;*/
		cout << _i << endl;
	}
};

class D
{
private:

public:	
	int i;
    int d(F z, int b = 20)
	{
		i = z._i + b;
		cout << i << endl;
		return i;
	}
};
class A
{
private:
	int i;
public:
	A(F y, D x, int d=5)
	{
		i = y._i + x.d(y._i) + d;
		cout << i << endl;
	}
};

int main()
{
	F a(2);
	D b;
	b.d(a);
	A c(a,b);
    return 0;
}
