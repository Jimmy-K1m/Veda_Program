#include <string>
#include <iostream>

using namespace std;

int main() {

	string song("Falling in love with you");
	string elvis_1("Elvis");
	string elvis_2(" Presley");
	string elvis = elvis_1 + elvis_2;
	string singer;

	cout << song + "�� �θ� ���" << endl;
	
	getline(cin, singer);
	if (singer == elvis)
		cout << "�¾ҽ��ϴ�" << endl;
	else
		cout << "Ʋ�Ƚ��ϴ�" << endl;

	return 0;
}