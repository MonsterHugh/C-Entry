// c++入门15（队列操作函数）.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct _NODE
{
	int value;
	struct _NODE *next;

	_NODE(int value) : value(value), next(NULL) {};
}NODE, *PTRNODE;
void enqueue(PTRNODE &head, PTRNODE &tail, int value)
{
	if (head == NULL)
	{
		head = new NODE(value);
		tail = head;
	}
	else
	{
		PTRNODE newNode = new NODE(value);

		tail->next = newNode;
		tail = newNode;
	}
}
int dequeue(PTRNODE &head, PTRNODE &tail)
{
	if (head == NULL)
	{
		tail = NULL;
		return -1;
	}

	PTRNODE temp = head;
	int res = temp->value;

	head = head->next;

	delete temp;

	return res;
}
void clear(PTRNODE &head, PTRNODE &tail)
{
	if (head == NULL)
	{
		tail = NULL;
		return;
	}

	while (head != NULL)
		dequeue(head, tail);
}
void display(PTRNODE head)
{
	if (head == NULL)
	{
		cout << "empty" << endl;
		return;
	}

	PTRNODE temp = head;
	while (temp != NULL)
	{
		cout << temp->value << "->";

		temp = temp->next;
	}

	cout << endl;
}

int main(int argc, char *argv[])
{
	PTRNODE head = NULL, tail = NULL;

	for (int i = 0; i < 10; i++)
		enqueue(head, tail, i);

	cout << "init queue is: " << endl;
	display(head);

	cout << "please input a number to enqueue: ";
	int num = 0;
	cin >> num;
	enqueue(head, tail, num);

	cout << "after enqueue: " << endl;
	display(head);

	cout << "after dequeue: " << endl;
	dequeue(head, tail);
	display(head);

	clear(head, tail);

	cout << "after clear: " << endl;
	display(head);

	system("PAUSE");
	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
