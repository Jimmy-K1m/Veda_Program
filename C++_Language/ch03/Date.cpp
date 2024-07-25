#include <iostream>
#include <sstream>
#include <string>
#include "Date.h"
using namespace std;
Date::Date() {};
Date::Date(int year, int month, int day) { y = year; m = month; d = day; };
Date::Date(string s) {
	string temp;
	istringstream s1(s);

	int i = 0;
	while (getline(s1, temp, '/'))
	{
		if (i == 0)
			y = stoi(temp);
		else if (i == 1)
			m = stoi(temp);
		else
			d = stoi(temp);
		i++;
	}
};
int Date::show() { cout << y << "³â" << m << "¿ù" << d << "ÀÏ" << endl; return 0; };

int Date::getYear() { return y; };
int Date::getMonth() { return m; };
int Date::getDay() { return d; };