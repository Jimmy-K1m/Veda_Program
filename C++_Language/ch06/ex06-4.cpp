#include <iostream>
#include "circle.h"

using namespace std;

int main() {

	Circle* p = new Circle[10];
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumofCircles() << endl;
	
	delete[]p;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumofCircles() << endl;
	
	Circle a;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumofCircles() << endl;

	Circle b;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumofCircles() << endl;

	return 0;
}