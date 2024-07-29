#pragma once
#include <iostream>


class Circle {
private:
	int radius;
	static int numObject;

public:

	double getArea() const;
	void setRadius(int r);
	Circle();
	Circle(int r);
	~Circle();
	static int getNumofCircles();
	static void setDefault();
	//static void setNumObject();
};

//int Circle::numObject = 0;
