// c++入门17（队列类的创建及操作）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class Queue {
private:
	int *data;              //定义指向整型的指针，从而动态开辟内存
	int head, tail, length;   //head指向队首,tail指向队尾,length表示队列的长度
public:
	Queue(int length_input) {       //构造函数,对新声明的队列对象进行初始化
		data = new int[length_input];      //动态开辟100个整型数据的空间
		length = length_input;              //为队列的长度赋初始值
		head = 0;                       //起初head为0，表示head值未改变的情况下,一直指向首元素
		tail = -1;                      //tail初始值为-1，表示此时队列为空,无任何数据元素
	}
	~Queue() {
		delete[] data;             //析构函数,删除动态开辟的内存
	}
	void push(int element) {       //入队操作,只能从队列的尾部插入数据元素
		if (tail + 1 < length) {        //队列未满的时候才能插入,否则则插入失败
			++tail;                 //队尾指针先往后移动一位
			data[tail] = element;   //再插入队尾指针指向的位置
		}
	}
	void pop() {
		if (tail < 0) {     //队列为空,出队失败
			return;
		}
		++head;          //队首指针后移,表示原来队首已出列
	}
	int top() {
		if (tail > -1) {      //队列不为空的情况下才能获取队首元素
			return data[head];
		}
	}
	void output() {
		for (int i = head; i <= tail; i++) {     //从队首一直遍历到队尾
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	Queue queue(100);               //声明一个队列对象,并初始化
	for (int i = 1; i <= 10; ++i) {
		queue.push(i);             //将1-10这10个数据元素依次插入队列中
	}
	queue.output();             //调用输出的方法
	cout << "当前的队首元素为:" << queue.top() << endl;
	queue.pop();               //出队
	queue.output();             //调用输出的方法
	cout << "出队操作后的队首元素为:" << queue.top() << endl;
	return 0;
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
