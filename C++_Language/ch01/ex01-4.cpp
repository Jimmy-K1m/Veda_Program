#include <cstring>
#include <iostream>
using namespace std;

int main() {
	int n = strlen("hello");

	cout << n << endl;

	char name[10];
	/*
	cin >> name;
	cout << name << endl;
	*/
	cin.getline(name, 10, '\n'); 
	cout << name << endl;

	return 0;
}