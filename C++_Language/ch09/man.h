#pragma once
//#include "person.h"
//
//class Man : public Person {
//public:
//	Man() {}
//	Man(const string& name, int age) :Person(name, age, Person::male) {
//	}
//	void show() const
//	{
//		Person::show();
//		cout << "³²¼º" << endl;
//	}
//};
#include <iostream>
#include <string>
using namespace std;

#include "human.h"


class Man : public Human {
public:
	Man();
	virtual ~Man();
	Man(const string& name, int age);
	virtual void show();
};

