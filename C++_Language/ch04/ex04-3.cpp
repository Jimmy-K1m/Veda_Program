#include <iostream>

using namespace std;

int ___main() {
	int input;

	cin >> input;


	int* p = new int[input];

	int sum=0;
	
	for(int i = 0; i < input; i++)
	{
		cin >> *(p + i);
		sum += *(p + i);
	}
	/*
	for (int i = 0; i < input; i++)
	{
		cout << *(p + i) << endl;
	}
	*/
	cout << sum << endl;

	delete[]p;
	p = NULL;

	return 0;
}