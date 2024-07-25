#include <iostream>
#include "circle.h"
using namespace std;

int _____main() {

	int temp_r;
	Circle* p;
	while (1) {
		
		cin >> temp_r;

		if (temp_r == -1) break;

		p = new Circle;
		p->setRadius(temp_r);

		cout << "Area is " << p->getArea() << endl;


		delete p;
		p = NULL;
	}
	

	return 0;
}