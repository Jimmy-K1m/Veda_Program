#include <iostream>
#include <string>
using namespace std;
#include "human.h"


void Human::show() {
	{
		cout << name << ": " << age << endl;
	}

}

Human::Human(const string& name, int age) : name(name), age(age)
{
	//this->name = name; this->age = age;
	cout << "Human ������ �Լ� (�Ű�����) " << endl;
}

Human::~Human() {
	cout << "Human �Ҹ��� �Լ�" << endl;
}
