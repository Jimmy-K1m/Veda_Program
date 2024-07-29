#pragma once


class Stack {

	int size; // 스택 크기
	int top = -1; // 스택의 마지막 데이터 위치
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