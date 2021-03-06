// c++入门08（复数运算符重载）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Complex
{
private:
	float _real;
	float _image;
public:
	Complex(float real = 0, float image = 0)
	{
		this->_real = real;
		this->_image = image;
	}
	void display()
	{
		cout << "复数为：" << this->_real << "+" << this->_image << "i" << endl;
	}
	//前置--
	friend Complex & operator--(Complex &c);
	//后置--
	friend Complex operator--(Complex &c, int);
public:
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	//前置++
	Complex & operator++()
	{
		this->_real++;
		this->_image++;
		return *this;
	}
	//后置++
	Complex operator++(int)
	{
		Complex temp = *this;
		this->_real++;
		this->_image++;
		return temp;
	}
};
Complex Complex::operator+(const Complex& c)
{
	this->_real = this->_real + c._real;
	this->_image = this->_image + c._image;
	return *this;
}
Complex Complex::operator-(const Complex& c)
{
	this->_real = this->_real - c._real;
	this->_image = this->_image - c._image;
	return *this;
}
//前置--
Complex & operator--(Complex &c)
{
	c._image--;
	c._real--;
	return c;
}
//后置--
Complex operator--(Complex &c, int)
{
	Complex temp = c;
	c._image--;
	c._real--;
	return temp;
}
int main()
{
	Complex t1(1, 2);
	t1.display();
	++t1;
	t1.display();
	--t1;
	t1.display();
	Complex t2(3, 4);
	t2.display();
	t2++;
	t2.display();
	t2--;
	t2.display();
	cout << "hello world!\n";
	return 0;
}


