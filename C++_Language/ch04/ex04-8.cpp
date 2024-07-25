#include <iostream>
#include <string>

using namespace std;

int _________main() {

	string s1;
	string s2("Hello C++");

	cout << s1.length() << ", "<< s1.size() << ", "<< s1.capacity() << endl;
	cout << s2.length() << ", " << s2.size() << ", " << s2.capacity() << endl;

	s2 = s2 + "...........";

	cout << s2.length() << ", " << s2.size() << ", " << s2.capacity() << endl;
	cout << s2.at(2) << ", " << s2[2] << endl; 

	s2 = s2.append("app");
	cout << s2 << endl;
	cout << s2.find("..") << endl;


	/*
	s2.replace(0, 3, "hEL");
	cout << s2 << endl;

	s2.erase(0, 5);
	cout << s2 << endl;

	s2.clear();
	cout << s2<< endl;

	*/

	string str_temp1 = "apple";
	string str_temp2 = "bear";

	cout << str_temp2.compare(str_temp1) << endl;

	return 0;
}