#include <iostream>
#include <string>

using namespace std;

int add(int a, int b)
{
	return a + b;
}
/*
int add(int a, int& b)
{
	b = b + a;
	return b;
}
*/
int ___main() {
	
	int s = 10, t = 20;
	cout << add(s, t) << endl;
	return 0;
}