#include<iostream>

using namespace std;

#include "point.h"

void Point::set(int x, int y) {
	this->x = x; this->y = y;
}

void Point::showPoint(){
	cout << "(" << x << "," << y << ")" << endl;
}

Point::Point() { cout << "parent"; }