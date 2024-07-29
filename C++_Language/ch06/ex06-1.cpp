#include <iostream>
#include <string>

using namespace std;

int getMin(int x, int y) {
	return x < y ? x : y;
}

double getMin(double x, double y) {
	return x < y ? x : y;
}

char getMin(char x, char y) {
	return x < y ? x : y;
}

string getMin(string x, string y)
{
	return x < y ? x : y;
}
int getMin(int* arr, int size)
{
	int min = arr[0];

	for (int i = 0; i < size; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}


int _main()
{
	cout << getMin(10, 20) << endl;
	cout << getMin(10.5, 20.5) << endl;
	cout << getMin('a','b') << endl;
	cout << getMin("apple", "banana") << endl;

	int arr[] = {1,2,3,4,5,0,7};

	cout << getMin(arr, 7) << endl;

	return 0;
}