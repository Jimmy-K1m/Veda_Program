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
	cout << "Human 생성자 함수 (매개변수) " << endl;
}

Human::~Human() {
	cout << "Human 소멸자 함수" << endl;
}
