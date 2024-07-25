#include <iostream>
#include "circle.h"

using namespace std;
/*
int main() {
	Circle circleArray[3];

	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[1].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << circleArray[i].getArea() << endl;
	}

	Circle* p = circleArray;

	for (int i = 0; i < 3; i++)
	{
		cout << p[i].getArea() << endl;
	}
}
*/

int _main() {
	Circle circleArray[2][3] = { {Circle(10), Circle(20), Circle(30)},{Circle(40), Circle(50), Circle(60)} };

	//circleArray[0].setRadius(10);
	//circleArray[1].setRadius(20);
	//circleArray[1].setRadius(30);

	for (int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
			cout << circleArray[i][j].getArea() << endl;
	}

	Circle (*p)[3] = circleArray;//배열 포인터 이용

	int arr[2][3] = { {1,2,3}, {1,2,3} };
	int* ptr[2] = {  arr[0],arr[1] };
	int** dptr = ptr;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(*(dptr + i) + j) << endl;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << (*p+j)->getArea() << endl;

		p++;
	}
	return 0;
}