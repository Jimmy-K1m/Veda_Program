#include "woman.h"
#include <string>



Woman::Woman() {}

Woman::Woman(const string& name, int age) {
	this->name = name;
	this->age = age;
}

Woman::~Woman() {
	cout << "Woman �Ҹ��� �Լ�" << endl;
}

void Woman::show() {
	Human::show();
	cout << "����" << endl;
}