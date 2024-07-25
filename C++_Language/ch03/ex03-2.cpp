#include <iostream>
#include <string>

using namespace std;

class Rectangular {
public:
	int width;
	int height;
	Rectangular() { width = 0; height = 0; }
	Rectangular(int a, int b) { width = a; height = b; }
	Rectangular(int a) { width = a; height = a; }

	bool isSquare()
	{
		/*
		if (width == height) return 1;
		else return 0;
		*/
		return (width == height);
	}

	double getArea() { return width * height; }
};


int main() {
	Rectangular rect1;
	Rectangular rect2(3,5);
	Rectangular rect3(3);

	if (rect1.isSquare()) cout << "rect1은 정사각형" << endl;
	if (rect2.isSquare()) cout << "rect2은 정사각형" << endl;
	if (rect3.isSquare()) cout << "rect3은 정사각형" << endl;
}
