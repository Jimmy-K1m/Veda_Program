#include <iostream>
#include "circle.h"

using namespace std;

Circle& operator*=(Circle& objA , Circle& objB) {
	objA.radius = objA.radius * objB.radius;

	return objA;
}

ostream& operator<<(ostream& s, Circle obj) {
	s << obj.radius << " ";

	return s;
}

int main() {
	Circle a;
	Circle b(5);

	Circle c = a + b;

	cout << c.radius << endl; // 6
	cout << (a == b) << endl; // 0
	a += b; 
	cout << a.radius << endl; // 6
	cout << (a == c) << endl; // 1

	b *= c;

	cout << b.radius << endl; //30

	cout << (b + 3).radius << endl;
	cout << b << c;


	return 0;
}
/*
Circle operator+(Circle& obj); // radius + radius
bool operator==(Circle& obj);// radius == radius
Circle& operator+=(Circle& obj); // radius = radius + obj.radius
*/