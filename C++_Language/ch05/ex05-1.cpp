#include <iostream>

using namespace std;

int _main() {

	int n = 10;
	int& refn = n;

	cout << &n << endl;
	cout << &refn << endl;

	return 0;
}
