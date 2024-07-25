#include <iostream>
#include "circle.h"

using namespace std;

int ____main()
{
	Circle* p, *q;

	p = new Circle;
	q = new Circle(30);

	cout << p->getArea() << endl << q->getArea() << endl;

	delete p, q;
	return 0;
}