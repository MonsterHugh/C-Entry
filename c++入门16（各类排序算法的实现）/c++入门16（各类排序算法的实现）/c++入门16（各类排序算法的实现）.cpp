// c++入门16（各类排序算法的实现）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

void insertion_sort(int a[], int n);//插入排序（insertion sort）
void selection_sort(int a[], int n);//选择排序（selection sort）
void bubble_sort(int a[], int n);//冒泡排序（bubble sort）
void quick_sort(int a[], int l, int r);//快速排序（quick sort）
void heap_sort(int a[], int length);//堆排序（heap sort）
void merge_sort(int a[], int first, int last, int temp[]);//归并排序（merge sort）
void shell_sort(int a[], int n);//希尔排序（shell sort）:对插入排序的优化算法
void createBST(BST** tree, int a[], int n);//二叉树排序（binary tree sort）
void count_sort(int a[], int b[], int n);//计数排序（count sort）
void radix_sort(int* pDataArray, int iDataNum);//基数排序（radix sort）


/*插入排序（insertion_sort）*/
void insertion_sort(int a[], int n) {
	int i, j, v;
	for (i = 1; i < n; i++) {
		//如果第i个元素小于第j个，则第j个向后移动
		for (v = a[i], j = i - 1; j >= 0 && v < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = v;
	}

}

/*选择排序（selection_sort）*/
void selection_sort(int a[], int n) {
	int i, j, pos, tmp;
	for (i = 0; i < n - 1; i++) {
		//寻找最小值的下标
		for (pos = i, j = i + 1; j < n; j++)
			if (a[pos] > a[j])
				pos = j;
		if (pos != i) {
			tmp = a[i];
			a[i] = a[pos];
			a[pos] = tmp;
		}
	}
}

/*冒泡排序（bubble_sort）*/
void bubble_sort(int a[], int n) {
	int i, j, lastSwap, tmp;
	for (j = n - 1; j > 0; j = lastSwap) {
		lastSwap = 0;     //每一轮要初始化为0，防止某一轮未发生交换，lastSwap保留上一轮的值进入死循环
		for (i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				//最后一次交换位置的坐标
				lastSwap = i;
			}
		}
	}
}

/*快速排序（quick_sort）*/
int mpartition(int a[], int l, int r) {
	int pivot = a[l];

	while (l < r) {
		while (l < r && pivot <= a[r]) r--;
		if (l < r) a[l++] = a[r];
		while (l<r && pivot>a[l]) l++;
		if (l < r) a[r--] = a[l];
	}
	a[l] = pivot;
	return l;
}
void quick_sort(int a[], int l, int r) {

	if (l < r) {
		int q = mpartition(a, l, r);
		quick_sort(a, l, q - 1);
		quick_sort(a, q + 1, r);
	}
}
//void quick_sort(int a[], int l, int r)
//{
//	sizeof(a);
//	if (low <= high)
//	{
//		return;
//	}
//	int i = l;
//	int j = r;
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
//	Qsort(a, l, i - 1);
//	Qsort(a, i + 1, r);
//}

/*堆排序（heap_sort）*/
void heapAdjust(int a[], int i, int nLength)//找到堆中最大的数放到堆顶
{
	int nChild;
	int nTemp;
	for (nTemp = a[i]; 2 * i + 1 < nLength; i = nChild)
	{
		// 子结点的位置=2*（父结点位置）+ 1
		nChild = 2 * i + 1;
		// 得到子结点中较大的结点
		if (nChild < nLength - 1 && a[nChild + 1] > a[nChild])
			++nChild;
		// 如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
		if (nTemp < a[nChild])
		{
			a[i] = a[nChild];
			a[nChild] = nTemp;
		}
		else
			// 否则退出循环
			break;
	}
}
void heap_sort(int a[], int length)// 堆排序算法
{
	int tmp;
	// 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
	//length/2-1是第一个非叶节点，此处"/"为整除
	for (int i = length / 2 - 1; i >= 0; --i)
		heapAdjust(a, i, length);
	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for (int i = length - 1; i > 0; --i)
	{
		// 把第一个元素和当前的最后一个元素交换，
		// 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
	  ///  Swap(&a[0], &a[i]);
		tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		// 不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
		heapAdjust(a, 0, i);
	}
}

/*归并排序（merge_sort）*/
void mergearray(int a[], int first, int mid, int last, int temp[])//将两个有序数列数列合并
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void merge_sort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		merge_sort(a, first, mid, temp);    //左边有序
		merge_sort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}


/*希尔排序（shell_sort）*/
void shell_sort(int a[], int n)
{
	int d, i, j, temp; //d为增量
	for (d = n / 2; d >= 1; d = d / 2) //增量递减到1使完成排序
	{
		for (i = d; i < n; i++)   //插入排序的一轮
		{
			temp = a[i];
			for (j = i - d; (j >= 0) && (a[j] > temp); j = j - d)
			{
				a[j + d] = a[j];
			}
			a[j + d] = temp;
		}
	}
}

/*二叉树排序（binary_tree_sort）*/
struct BST //定义二叉树节点
{
	int number; //保存数组元素的值
	struct BST* left;
	struct BST* right;
};
void insertBST(BST** tree, int v) //创建二叉树节点并按左树小右树大的规律向节点插入数据
{
	if (*tree == NULL) {
		*tree = new BST;
		(*tree)->left = (*tree)->right = NULL;
		(*tree)->number = v;
		return;
	}
	if (v < (*tree)->number)
		insertBST(&((*tree)->left), v);
	else
		insertBST(&((*tree)->right), v);
}
void printResult(BST* tree) //对二叉树进行中序遍历得出排序后的数组
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		printResult(tree->left);
	std::cout << tree->number << "  ";
	if (tree->right != NULL)
		printResult(tree->right);
}
void createBST(BST** tree, int a[], int n) //创建二叉树并对其遍历得到排序后的数组
{
	*tree = NULL;
	for (int i = 0; i < n; i++)
		insertBST(tree, a[i]);
	printResult(*tree);
}

/*计数排序（count_sort）*/
void findArrMaxMin(int a[], int size, int *min, int *max)//找出待排序的数组中最大和最小的元素
{
	if (size == 0) {
		return;
	}
	if (size == 1) {
		*min = *max = a[0];
		return;
	}
	*min = a[0] > a[1] ? a[1] : a[0];
	*max = a[0] <= a[1] ? a[1] : a[0];
	int i, j;
	for (i = 2, j = 3; i < size, j < size; i += 2, j += 2) {
		int tempmax = a[i] >= a[j] ? a[i] : a[j];
		int tempmin = a[i] < a[j] ? a[i] : a[j];

		if (tempmax > *max)
			*max = tempmax;
		if (tempmin < *min)
			*min = tempmin;
	}
	//如果数组元素是奇数个，那么最后一个元素在分组的过程中没有包含其中，
	//这里单独比较
	if (size % 2 != 0) {
		if (a[size - 1] > *max)
			*max = a[size - 1];
		else if (a[size - 1] < *min)
			*min = a[size - 1];
	}
}
void count_sort(int a[], int b[], int n) 
{
	int max, min;
	findArrMaxMin(a, n, &min, &max);
	int numRange = max - min + 1;
	int* counter = new int[numRange];
	int i, j, k;
	for (k = 0; k < numRange; k++)
		counter[k] = 0;
	for (i = 0; i < n; i++)
		counter[a[i] - min]++;
	for (k = 1; k < numRange; k++)
		counter[k] += counter[k - 1];
	for (j = n - 1; j >= 0; j--) {
		int v = a[j];
		int index = counter[v - min] - 1;
		b[index] = v;
		counter[v - min]--;
	}
}

/*基数排序（radix_sort）*/
int getNumInPos(int num, int pos) //获得某个数字的第pos位的值
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}
#define RADIX_10 10    //十个桶，表示每一位的十个数字
#define KEYNUM 5     //整数位数
void radix_sort(int* pDataArray, int iDataNum)
{
	int *radixArrays[RADIX_10];    //分别为0~9的序列空间
	for (int i = 0; i < RADIX_10; i++)
	{
		radixArrays[i] = new int[iDataNum];
		radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
	}

	for (int pos = 1; pos <= KEYNUM; pos++)    //从个位开始到31位
	{
		for (int i = 0; i < iDataNum; i++)    //分配过程
		{
			int num = getNumInPos(pDataArray[i], pos);
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = pDataArray[i];
		}

		for (int i = 0, j = 0; i < RADIX_10; i++) //写回到原数组中，复位radixArrays
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
				pDataArray[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0;
		}
	}
}


int main()
{
	int arr[] = { 7, 8, 8, 9, 5, 16, 5, 3,56,21,34,15,42 };
	int temp[] = {94,6,8,4,6,8,4,1,5,8,94,8,4};
	int n = sizeof(arr) / sizeof(int);
	int m = sizeof(temp) / sizeof(int);

	BST* root;

	insertion_sort(arr, n);//插入排序（insertion sort）
	selection_sort(arr, n);//选择排序（selection sort）
	bubble_sort(arr, n);//冒泡排序（bubble sort）
	quick_sort(arr, 1, n);//快速排序（quick sort）
	heap_sort(arr, n);//堆排序（heap sort）
	merge_sort(arr, 1, n, temp);//归并排序（merge sort）
	shell_sort(arr, n);//希尔排序（shell sort）:对插入排序的优化算法
	createBST(&root, arr, n);//二叉树排序（binary tree sort）
	count_sort(arr, temp, n);//计数排序（count sort）
	radix_sort(int* pDataArray, int iDataNum);//基数排序（radix sort）
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
