#pragma once
#include <string>

using namespace std;

class Person {
	string name;
public :
	Person(string name); 
	string getName(); 
	Person();
	void setName(string name);
};