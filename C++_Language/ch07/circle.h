#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

class Circle {
public:
	int radius;
	double getArea();
	void setRadius(int r);
	Circle();
	Circle(int r);
	//Circle operator+(Circle& obj); // radius + radius
	Circle operator+(int n);
	bool operator==(Circle& obj);// radius == radius
	Circle& operator+=(Circle& obj); // radius = radius + obj.radius

	friend Circle& operator*=(Circle& obja, Circle& objb);
	friend Circle operator+(Circle& c1, Circle& c2);
	friend ostream& operator<<(ostream& s, Circle obj);
};
