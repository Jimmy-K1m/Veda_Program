

#include "circle.h"
using namespace std;

int Circle::numObject = 0;
double Circle::getArea() const { return 3.14 * radius * radius; };
void Circle::setRadius(int r) { radius = r; }
Circle::Circle() { radius = 1; numObject += 1; }
Circle::Circle(int r) { radius = r; numObject += 1; }
Circle::~Circle() { numObject -= 1; }
int Circle::getNumofCircles() { return numObject; }
void Circle::setDefault() { numObject = 0; }


//void Circle::setNumObject() { numObject = 0; }

/*class Circle {
private:
	int radius;
	static int numObject;

public:

	int radius;
	double getArea();
	void setRadius(int r);
	Circle();
	Circle(int r);
	~Circle();
	static int getNumofCircles();

};
*/