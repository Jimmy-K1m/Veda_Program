#include "woman.h"
#include <string>



Woman::Woman() {}

Woman::Woman(const string& name, int age) {
	this->name = name;
	this->age = age;
}

Woman::~Woman() {
	cout << "Woman 소멸자 함수" << endl;
}

void Woman::show() {
	Human::show();
	cout << "여성" << endl;
}