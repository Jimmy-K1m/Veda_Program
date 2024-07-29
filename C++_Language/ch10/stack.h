
#pragma once

#include <iostream>
using namespace std;

template <class T>
class Stack {

	int size; // 스택 크기
	int top = -1; // 스택의 마지막 데이터 위치
	T* buffer;

public:
	Stack();
	Stack(int s);
	~Stack();
	Stack(Stack& sobj);
	bool pop(T& data);

	bool push(T value);

	void showData(Stack& s);
	void Pop(int& data);
	int getSize();
	bool setSize(int s);
	int getTop();
	T getData(int pos);
};


#include <iostream>
#include "stack.h"

//int size; // 스택 크기
//int top; // 스택의 마지막 데이터 위치
//int* buffer;
template <class T>
Stack<T>::Stack() {
	size = 10;
	buffer = new T[size];
}
template <class T>
Stack<T>::Stack(int s) {
	size = s;
	buffer = new T[size];
}

template <class T>
Stack<T>::Stack(Stack& sobj) {
	this->size = sobj.size;
	this->top = sobj.top;
	this->buffer = new int[this->size];

	for (int i = 0; i <= this->top; i++)
	{
		this->buffer[i] = sobj.buffer[i];
	} // memcpy(this->buffer, sobj.buffer, sizeof(int)*(top+1))
}
template <class T>
Stack<T>::~Stack() {
	delete[] buffer;
}
/*
template <class T>
bool Stack<T>::pop() {
	if (top < 0)
		return false;
	else
	{
		top--;
		return true;
	}
}
*/
template <class T>
bool Stack<T>::pop(T& data)
{
	if (top < 0)
		return false;
	else
	{
	
		data = buffer[top--];
		return true;
	}
}

template <class T>
bool Stack<T>::push(T value) {
	//int* temp = new int(value);

	if ((top + 1) >= size)
		return false;
	else {
		buffer[++top] = value;

		return true;
	}

}
template <class T>
int Stack<T>::getSize() {

	return top + 1;
}

template <class T>
bool Stack<T>::setSize(int s) {

	int* buffer_temp = new int[s];
	for (int i = 0; i <= top; i++)
		buffer_temp[i] = buffer[i];
	delete[]buffer;

	buffer = new int[s];
	for (int i = 0; i <= top; i++)
		buffer[i] = buffer_temp[i];
	delete[]buffer_temp;
	size = s;


	//(buffer + top + 1) = new int[s- size];
	return true;
}
template <class T>
int Stack<T>::getTop() {
	return buffer[top];
}

template <class T>
T Stack<T>::getData(int pos) {
	if ((pos) > top)
	{
		return -1;
	}

	else
		return buffer[pos];
}

