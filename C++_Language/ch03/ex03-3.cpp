
#include <iostream>
#include "rectangular.h"

using namespace std;



//Rectangular globalrect(1000);

int main() {
	Rectangular rect1;
	Rectangular rect2(3, 5);
	Rectangular rect3(3);

	if (rect1.isSquare()) cout << "rect1�� ���簢��" << endl;
	if (rect2.isSquare()) cout << "rect2�� ���簢��" << endl;
	if (rect3.isSquare()) cout << "rect3�� ���簢��" << endl;

	rect2.~Rectangular();
	cout << rect2.width << endl;
	cout << rect2.height << endl;

}
