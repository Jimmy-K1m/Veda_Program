#include <iostream>
#include "circle.h"


using namespace std;


void increaseCircle(Circle& c)
{
	int r = c.getRadius();
	c.setRadius(r + 1);
}
int ___main() {
	Circle waffle(30);
	increaseCircle(waffle);
	cout << waffle.getRadius() << endl;

	return 0;
}