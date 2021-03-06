// c++入门10（快速排序算法的实现）.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//#include <iostream>
//
//using namespace std;
//
//void Qsort(int a[], int high, int low)
//{
//	sizeof(a);
//	if (low <= high)
//	{
//		return;
//	}
//	int i = high;
//	int j = low;
//	int key = a[i];/*用字表的第一个记录作为枢轴*/
//
//	while (i < j)
//	{
//		while (i < j && a[j] <= key)
//		{
//			j--;
//		}
//		a[i] = a[j];/*将比第一个大的移到前端*/
//
//		while (i < j && a[i] >= key)
//		{
//			i++;
//		}
//		a[j] = a[i];/*将比第一个小的移到后端*/
//	}
//	a[i] = key;/*枢轴记录到位*/
//	//for (int z = 0; z < sizeof(a) / sizeof(int); z++)
//	//{
//	//	cout << a[z] << " ";
//	//}
//	//cout << endl;
//	Qsort(a, high, i - 1);
//	Qsort(a, i + 1, low);
//	/*第一遍快速排序不会直接得到最终结果，只会把比k大和比k小的数分到k的两边。
//	为了得到最后结果，需要再次对下标i两边的数组分别执行此步骤，然后再分解数组，
//	直到数组不能再分解为止（只有一个数据），才能得到正确结果。*/
//}
////斐波那契数列：递归
//int Fibonacci(int n)
//{
//	if (n == 0)
//		return 1;
//	if (n == 1)
//		return 1;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//int main()
//{	
//	/*int n;
//	int *a = new int ();
//	cin >> n;
//	cout << "斐波那契数列为：" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << Fibonacci(i) << " ";
//		a[i] = Fibonacci(i);
//	}*/
//	int a[] = { 1,5,1,7,2,8 };
//
//	cout << endl << "快速排列后的数列为：" << endl;
//	//Qsort(b, 0, n - 1);/*第三个参数要减1否则内存越界*/
//	Qsort(a, 0, sizeof(a) / sizeof(int));
//	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
//	{
//		cout << a[i] << " ";
//	}
//	return 0;
//}
//
#include "stdafx.h"
#include<iostream>
#include <vector>
using namespace std;

void qSort(vector<int>& a, int low, int high)
{
	if (low >= high)
		return;
	//1. 找a[0]作为参考值
	int k = a[low];
	//2. 将数组拆分成两部分，前部分小于a[0],后部分大于a[0]
	int tL = low, tH = high;
	int sp = low;
	while (tL < tH)
	{
		while (a[tL] <= k && tL < tH) tL++;
		while (a[tH] >= k && tL < tH) tH--;
		if (tH == tL && a[tL] > k)
		{
			a[sp] = a[tL - 1];
			sp = tL - 1;
		}
		else
		{
			a[sp] = a[tH];
			a[tH] = a[tL];
			/*a[tH] = temp;*/
			sp = tL;
			tL++;
		}
	}
	a[sp] = k;
	/*a[low] = a[tL];
	a[tL] = k;*/
	//3. 递归拆分后的两部分

	qSort(a, low, sp - 1);
	qSort(a, sp + 1, high);
}

int main()
{
	vector<int> arr = { 6,4,8,9,4,6,5,4,8,8,5,6,3,4,8,16,5,6,9,69 };
	qSort(arr, 0, arr.size()-1);
	for (int i = 0; i < arr.size(); i++)
	{
        cout << arr[i] << " ";
	}
	return 0;
}