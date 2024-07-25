#include <iostream>
#include "family.h"
#include "person_.h"
#include <string>
//setName
using namespace std;

Family::Family(string name, int size) {

	this->size = size;
	p = new Person[size];
}
void Family::setName(int i, string name) {
	p[i].setName(name);
}
void Family::show()
{
	for (int i = 0; i < size; i++)
		cout << p[i].getName() << endl;
}
Family::~Family() {
	delete[]p;
}

