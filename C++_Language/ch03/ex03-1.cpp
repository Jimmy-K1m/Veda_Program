#include <string>
#include <iostream>

using namespace std;
/*
class Circle {
public:
	int radius = 5;
	double getArea() { return 3.14 * radius * radius; }
	Circle() : Circle(10) {}
	Circle(int r) : radius(r) { }
};
*/

class Circle {
public:
	int radius;
	double getArea() { return 3.14 * radius * radius; }
	Circle() {};
	Circle(int r) { radius = r; }
};

/*
Circle::Circle() {

}
Circle::Circle(int r) {
	radius = r;
}
*/
class Rect {
public:
	int width;
	int height;
	double getArea() { return width * height; }
};

/*
double Circle::getArea() {
	return 3.14 * radius * radius;
}
*/
int main() {
	Circle donut;
	donut.radius = 1;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 20;
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;


	Rect rect;
	rect.width = 5;
	rect.height = 20;

	cout << "rect 면적은 " << rect.getArea() << endl;
	return 0;
}

/*
class Rectangular {
public:
	int width;
	int height;
	double getArea() { return width * height; }
};
*/