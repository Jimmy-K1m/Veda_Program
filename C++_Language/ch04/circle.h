#pragma once
#include <stdlib.h>

class Circle {
public:
	int radius;
	double getArea();
	void setRadius(int r);
	Circle();
	Circle(int r);
};

