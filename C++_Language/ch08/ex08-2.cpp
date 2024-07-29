#include <iostream>
#include <string>

using namespace std;

#include "colorpoint.h"
#include "point.h"




int __main() {
	Point p;
	p.set(2, 3);
	p.showPoint();

	ColorPoint cp1;
	cp1.set(3, 4);
	cp1.setColor("Red");
	cp1.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");

	cout << ((cp1.equals(cp2)) ? "true" : "false");

	return 0;
}