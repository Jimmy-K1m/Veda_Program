#pragma once
//#include "person.h"
//
//class Woman : public Person {
//public:
//	Woman() {}
//	Woman(const string& name, int age) :Person(name, age, Person::male) {
//	}
//	void show() const
//	{
//		Person::show();
//		cout << "¿©¼º" << endl;
//	}
//};
#include <iostream>
#include <string>
using namespace std;
#include "human.h"

class Woman : public Human{
public:
	Woman();
	virtual ~Woman();
	Woman(const string& name, int age);
	void show();
};