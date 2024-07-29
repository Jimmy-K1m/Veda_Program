#include <iostream>
#include "circle.h"

using namespace std;

int main() {

	Circle* p = new Circle[10];
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumofCircles() << endl;
	
	delete[]p;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumofCircles() << endl;
	
	Circle a;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumofCircles() << endl;

	Circle b;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumofCircles() << endl;

	return 0;
}