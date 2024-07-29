#include "stack.h"
#include <iostream>

using namespace std;

int ___main()
{
	int temp_i = 0;
	Stack<int> istack;
	istack.push(3);
	//istack.push(5);
	istack.pop(temp_i);

	cout << temp_i << endl;


	double temp_d = 0;
	Stack<double> dstack;
	dstack.push(3.5);
	//dstack.push(4.3);
	dstack.pop(temp_d);

	cout << temp_d << endl;


	return 0;
}