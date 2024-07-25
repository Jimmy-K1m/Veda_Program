#include <iostream>
using namespace std;

double area(int r);

double area(int r)
{
	return 3.14 * r * r;
}

int main()
{
	int n;
	char c = '#';
	cin >> n ;
	cout << c << " " << 5.5 << '-' << n << endl;
	cout << 5.5 - n << endl;

	return 0;
}