#pragma once
#include <string>
using namespace std;
#include "point.h"


class ColorPoint : public Point {
protected:
	string color;
public:
	ColorPoint();
	void setColor(string color);
	void showColorPoint();
	bool equals(ColorPoint p);
};


