#include <string>
#include <iostream>

using namespace std;

#include "colorpoint.h"

void ColorPoint::setColor(string color) {
	this->color = color;

	}
void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
	}

bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color)
		return true;
	else
		return false;
}
ColorPoint::ColorPoint()
{
	cout << "ÀÚ½Ä" << endl;
}
