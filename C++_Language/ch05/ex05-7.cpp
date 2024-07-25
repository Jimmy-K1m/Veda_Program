#include <iostream>
#include <string>

using namespace std;

class Test {
	int n;
public:
	
	Test(int n) { this->n = n; }
	int getTest() { return this->n; }

};


int ________main() {

	int num(10);
	string str("hello");

	int num2(num);

	cout << num << "," << num2 << endl;

	Test t1(20);
	Test t2(t1); // 복사 생성자

	cout << t1.getTest() << ", " << t2.getTest() << endl;
	return 0;

}