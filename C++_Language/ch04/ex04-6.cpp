#include <iostream>
#include "circle.h"
using namespace std;

// ���� ��ü �迭

int ______main() {

	Circle* ptr = new Circle[3]{Circle(10), Circle(20), Circle(30)};

	//circleArray[0].setRadius(10);
	//circleArray[1].setRadius(20);
	//circleArray[1].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
			cout << ptr[i].getArea() << endl;
	}

	delete[]ptr;

	return 0;
}