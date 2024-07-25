#include <stdlib.h>
#include "circle.h"

double Circle::getArea() { return 3.14 * radius * radius; };
void Circle::setRadius(int r) { radius = r; }
Circle::Circle() { radius = 1; }
Circle::Circle(int r) { radius = r; }