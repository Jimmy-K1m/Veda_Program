#pragma once


class Stack {

	int size; // ���� ũ��
	int top = -1; // ������ ������ ������ ��ġ
	int* buffer;

public:
	Stack();
	Stack(int s);
	~Stack();
	Stack(const Stack& sobj);
	bool pop();

	bool push(int value);

	void showData(Stack& s);
	void Pop(int& data);
	int getSize();
	bool setSize(int s);
	int getTop();
	int getData(int pos);
};