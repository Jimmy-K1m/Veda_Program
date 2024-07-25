#pragma once
#include <string>
#include <sstream>
class Date {
public:
	int y, m, d;
	Date();
	Date(int year, int month, int day);
	Date(std::string s);
	int show();

	int getYear();
	int getMonth();
	int getDay();
};