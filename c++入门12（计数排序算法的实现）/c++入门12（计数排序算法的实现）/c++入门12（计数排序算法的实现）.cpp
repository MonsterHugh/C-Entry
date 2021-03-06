// c++入门12（计数排序算法的实现）.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
const int MAXN = 100000;
const int k = 1000; // range
int a[MAXN], c[MAXN], ranked[MAXN];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++c[a[i]];
	}
	for (int i = 1; i < k; ++i)
		c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; --i)
		ranked[--c[a[i]]] = a[i];//如果是i表达的是原数标号，a[i]就是排序后的正确序列
	for (int i = 0; i < n; ++i)
		cout << ranked[i] << endl;
	return 0;
}

//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int arr[] = { 1,2,3,3,4,52,3,4,4,5,75,8,6,5,6,8,9,68,9,0,5,5,6,7,24,5 };
//	//int arr2[100] = {0};
//	//for (int a : arr)// for(int i = 0 ; i <20; i++ ) int a = arr[i]
//	//{
//	//	arr2[a]++;
//	//}
//	//for (int i = 0; i < 100; i++)
//	//{
//	//	if (arr2[i] != 0)
//	//		std::cout << i << "元素有" << arr2[i] << "个" << std::endl;
//	//}
//
//	/*hash_map实现计数排列*/
//	unordered_map<int, int> um_NumCount;
//	for (int a : arr)
//	{
//		if (um_NumCount.end() == um_NumCount.find(a))
//		{
//			um_NumCount[a] = 0;
//		}
//		um_NumCount[a]++;
//	}
//	for (pair<int, int> a2 : um_NumCount)
//	{
//		std::cout << a2.first << "元素有" << a2.second << "个" << std::endl;
//	}
//	return 0;
//}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
