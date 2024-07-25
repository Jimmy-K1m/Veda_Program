#include <iostream>
#include "stack.h"

using namespace std;

int _______main() {
	Stack *s1 = new Stack;
	Stack *s2 = new Stack(5);

	s1->push(10);
	s1->push(5);
	s1->push(4);
	s1->pop();

	cout << s1->getSize() << endl;
	cout << s1->getTop() << endl;
	cout << s1->getData(2) << endl;
 	cout << s1->getData(1) << endl;
	cout << s1->getData(0) << endl;

	delete s1;
	

	cout << s2->push(10) << endl;
	cout << s2->push(5) << endl;
	cout << s2->push(4) << endl;
	cout << s2->push(3) << endl;
	cout << s2->push(6) << endl;
	cout << s2->push(7)<< endl;

	s2->setSize(10);
	cout << s2->push(7) << endl;

	for (int i = 0; i < s2->getSize(); i++)
		cout << s2->getData(i) << endl;

	delete s2;

	return 0;
}