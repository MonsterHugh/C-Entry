// c++入门03（复数重载）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

class complex
{
public:
	complex()
	{}
	complex(double real, double image);
	/*complex operator+ (const complex &c)
	{
		complex temp;
		temp.real = real + c.real;
		temp.image = image + c.image;
		cout << "复数的和为：" << temp.real << "+" << temp.image << "i" << endl;
		return temp;
	}*/
	friend complex operator +(complex &C, complex &D)
	{
		
		D.image = C.image + D.image;
		D.real = C.real + D.real;
		return D;
	}
private:
	double real;
	double image;
};
complex::complex(double r, double i)
{
	this->real = r;
	this->image = i;
}

int main()
{
	double r1, r2, i1, i2;
	cin >> r1 >> r2;
	cin >> i1 >> i2;
	complex c;
	complex a(r1, i1);
	complex b(r2, i2);
	c = a + b;
	system("pause");
	return 0;
}

