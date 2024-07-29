#pragma once
#include <string>

class Human {
protected:
	string name;
	int age;
	
public:
	virtual void show();
	virtual ~Human();
	Human() { cout << "Human ±âº»" << endl; };
	Human(const string& name, int age);
};