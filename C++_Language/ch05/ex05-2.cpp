#include <iostream>
using namespace std;

void swap(int& a, int& b)

{
	int tmp = a;
	a = b;
	b = tmp;

}

int __main() {
	int x = 5, y = 3;

	swap(x, y);

	cout << "x: " << x << " y: " << y << endl;
}