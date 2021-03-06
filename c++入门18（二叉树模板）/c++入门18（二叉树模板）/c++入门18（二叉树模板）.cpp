// c++入门18（二叉树模板）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include"Tree.h"
#include<iostream>
 using namespace std;
 int main()
 {
  //是否进入程序
 int uscho ;   bool flag = true;//uscho：user choice的缩写
 cout << "敬告;请您务必按提示要求操作，如果您进行了规定以外的操作，由此造成的一切后果，将全部由您个人承担，程序开发者概不负责！" << endl;
  cout << "是否进入程序？进入请按1，否则按0;" << endl;
  cin >> uscho;
  if (uscho == 0) return 0;
  //用户选择类型
 while (flag)
  {
   cout << "请选择您所要创建二叉树的数据类型，输入类型前的数字进行选择;" << endl;
   cout << "1.整型  2.浮点  3.字符" << endl;
   cin >> uscho;
   if (uscho != 1 && uscho != 2 && uscho != 3)
   {
    cout << "您的输入有误！重新输入请按1，退出请按0：" << endl;
    cin >> uscho;
    if (uscho == 0)return 0;
    else  flag = false;
   }
   if (flag) flag = false;
   else flag = true;
  }
  switch (uscho)
  {
  case 1:
  {
      Tree<int> tree_int;
      tree_int.Operate();
      break;
  }
  case 2:
  {
      Tree<float> tree_float;
      tree_float.Operate();
      break;
  }
  case 3:
  {
      Tree<char> tree_char;
      tree_char.Operate();
      break;
  }
  default:
   cout << "您的输入有误！" << endl;
   break;
  }
  return 0;
 } 

//代码已经过测试，在VS2013上成功运行！ 
//
//发此文有两大目的： 
//
//1.和大家交流经验，供需要的人参考。 
//
//2.在下菜鸟，代码中难免有不妥之处，恳求大神批评指正。您的批评就是在下提高的起点，对于您的批评，在下将不胜感激！
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
