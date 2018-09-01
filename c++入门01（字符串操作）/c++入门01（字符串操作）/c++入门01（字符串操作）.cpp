// c++入门01（字符串操作）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str1[12] = "Hello";
	char str2[12] = "World!";
	char str3[12];
	int  len;
	int  value;

	// 复制 str1 到 str3
	strcpy(str3, str1);
	cout << "strcpy( str3, str1) : " << str3 << endl;

	// 连接 str1 和 str2
	strcat(str1, str2);
	cout << "strcat( str1, str2): " << str1 << endl;

	// 连接后，str1 的总长度
	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;

	//连接后，返回str1中str2第一次出现的位置的指针
	strstr(str1, str2);
	cout << "strstr(str1,str2):" << strstr(str1, str2) << endl;


	//比较str2和str3的长度
	value = strcmp(str2, str3);
	cout << "strcmp(str2,str3):" << value << endl;

	//返回字符串str3中字符l第一次出现的位置的指针
	strchr(str3, 'l');
	cout << "strchr(str3,'l'):" << strchr(str3, 'l') << endl;
	system("pause");
	return 0;
}
