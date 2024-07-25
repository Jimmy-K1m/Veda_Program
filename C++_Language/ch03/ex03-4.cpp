#include <iostream>
#include <string>
#include <sstream>
#include "Date.h"
// string의 파인드를 사용하여야 한다.
using namespace std;
/*
class Date {
public:
	int y, m, d;
	Date() {}
	Date(int year, int month, int day) { y = year; m = month; d = day; }
	Date(string s) {
		string temp;
		istringstream ss1(s);

		int i = 0;
		while (getline(ss1, temp, '/'))
		{
			if (i == 0)
				y = stoi(temp);
			else if (i == 1)
				m = stoi(temp);
			else
				d = stoi(temp);
			i++;
		}


	}
	int show() { cout << y << "년" << m << "월" << d << "일" << endl; return 0; }

	int getYear() { return y; }
	int getMonth() { return m; }
	int getDay() { return d; }
};*/

int main() {
	Date birth(2024, 3, 20);
	Date independence("1945/8/15");
	independence.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getYear() << ',';

	return 0;

}