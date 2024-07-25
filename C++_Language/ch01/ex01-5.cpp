#include <string>
#include <iostream>

using namespace std;

int main() {

	string song("Falling in love with you");
	string elvis_1("Elvis");
	string elvis_2(" Presley");
	string elvis = elvis_1 + elvis_2;
	string singer;

	cout << song + "를 부른 사람" << endl;
	
	getline(cin, singer);
	if (singer == elvis)
		cout << "맞았습니다" << endl;
	else
		cout << "틀렸습니다" << endl;

	return 0;
}