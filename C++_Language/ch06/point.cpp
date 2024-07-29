#include "point.h"
#include <iostream>

using namespace std;

void Point::show() {
	cout << this->width << endl;
	cout << this->height << endl;
}
Point::Point() {

}
Point::Point(int x, int y) {
	if (x > max_width)
		width = max_width;
	else
		width = x;

	if (x > max_height)
		height = max_height;
	else
		height = y;
}
void Point::setXY(int x, int y) {
	if (x > max_width)
		width = max_width;
	else
		width = x;

	if (y > max_height)
		height = max_height;
	else
		height = y;

}
void Point::setMax(int x, int y)
{
	max_width = x;
	max_height = y;
}

int Point::max_width = 0;
int Point::max_height = 0;