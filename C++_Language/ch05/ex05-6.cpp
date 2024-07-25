#include <iostream>
#include "stack.h"

using namespace std;


void showData(Stack& s) {

	for (int i = 0 ; i < s.getSize(); i++)
		cout << s.getData(i) << " ";

}
int main() {
	Stack s1(5);

	s1.push(123);
	s1.push(456);
	cout << "s1 ====> ";
	showData(s1);

	int data;
	s1.Pop(data);
	cout << '\n' << data << endl;

	Stack s2(s1);
	cout << "s2 ====> ";
	showData(s2);

	s2.Pop(data);
	cout << '\n' << data << endl;

	return 0;
}