#include <iostream>
#include <string>
#include "point.h"

using namespace std;

int _____main() {
	Point::setMax(1024, 512);

	Point p1(100, 100);
	p1.show();

	p1.setXY(2000, 1000);
	p1.show();


	Point p2;


	p2.setXY(512, 1000);
	p2.show();

	return 0;
}