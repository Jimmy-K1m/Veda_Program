#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }

};

template <class T>
void mySwap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b; 
	b = tmp;
}

int _main()
{
	int a = 4, b = 5;
	mySwap(a, b);
	cout << "a= " << a << " b= " << b << endl;

	double c = 4.3, d = 9.3;
	mySwap(c, d);
	cout << "c= " << c << " b= " << d << endl;

	Circle donut(5), pizza(20);

	mySwap(donut, pizza);
	cout << "donut= " << donut.getRadius() << " pizza= " << pizza.getRadius() << endl;

	return 0;
}