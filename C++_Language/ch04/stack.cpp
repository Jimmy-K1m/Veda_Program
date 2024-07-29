#include <iostream>
#include "stack.h"

//int size; // ���� ũ��
//int top; // ������ ������ ������ ��ġ
//int* buffer;

Stack::Stack() {
	size = 10;
	buffer = new int[size];
}
Stack::Stack(int s) {
	size = s;
	buffer = new int[size];
}

Stack::Stack(const Stack& sobj) {
	this->size = sobj.size;
	this->top = sobj.top;
	this->buffer = new int[this->size];

	for (int i = 0; i <= this->top; i++)
	{
		this->buffer[i] = sobj.buffer[i];
	} // memcpy(this->buffer, sobj.buffer, sizeof(int)*(top+1))
}
Stack::~Stack() {
	delete[] buffer;
}

bool Stack::pop() {
	if (top < 0)
		return false;
	else
	{
		top--;
		return true;
	}
}

void Stack::Pop(int& data)
{
	data = buffer[top--];	
}

bool Stack::push(int value) {
	//int* temp = new int(value);

	if ((top + 1) >= size)
		return false;
	else {
		buffer[++top] = value;
		return true;
	}

}

int Stack::getSize() {

	return top + 1;
}
bool Stack::setSize(int s) {

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
int Stack::getTop() {
	return buffer[top];
}
int Stack::getData(int pos) {
	if ((pos) > top)
	{
		return -1;
	}

	else
		return buffer[pos];
}

