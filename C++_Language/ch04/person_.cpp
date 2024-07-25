#include <iostream>
#include "family.h"
#include "person_.h"
#include <string>

Person::Person(){}
Person::Person(string name) { this->name = name; }
void Person::setName(string name) { this->name = name; }
string Person::getName() { return name; }