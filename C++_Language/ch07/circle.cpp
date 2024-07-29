#include <stdlib.h>
#include "circle.h"

double Circle::getArea() { return 3.14 * radius * radius; };
void Circle::setRadius(int r) { radius = r; }
Circle::Circle() { radius = 1; }
Circle::Circle(int r) { radius = r; }
/*
Circle Circle::operator+(Circle& obj) {
	Circle temp;

	temp.radius = this->radius + obj.radius;
	
	return temp;
}
*/
bool Circle::operator==(Circle& obj) {

	if (this->radius == obj.radius)
		return true;
	else
		return false;

}
Circle& Circle::operator+=(Circle& obj) {
	this->radius = this->radius + obj.radius;

	return *this;
}


Circle Circle::operator+(int n) {
	Circle temp;

	temp.radius = this->radius + n;

	return temp;
}

Circle operator+(Circle& c1, Circle& c2)
{
	Circle temp;

	temp.radius = c1.radius + c2.radius;

	return temp;

}

