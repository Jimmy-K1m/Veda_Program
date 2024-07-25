#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "?  ";

	int a;
	int b;
	char op;
	while (1) {
		cin >> a >> op >> b;

		if (op == '+')
		{
			cout << a << " " << op << " " << b << " = " << a + b << endl;
		}
		else if (op == '-')
		{
			cout << a << " " << op << " " << b << " = " << a - b << endl;
		}
		else if (op == '*')
		{
			cout << a << " " << op << " " << b << " = " << a * b << endl;
		}
		else
		{
			cout << a << " " << op << " " << b << " = " << a / b << endl;
		}
		cout << "?  ";
	}
	return 0;
}