#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		int n = *it;
		n = n * 2;
		*it = n;
	}

	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector <string> v1;
	v1.push_back("a");
	v1.push_back("b");
	v1.push_back("c");

	vector<string>::iterator it1;
	for (it1 = v1.begin(); it1 != v1.end(); it++)
	{
		string n = *it1;
		n = n + n;
		*it1 = n;
	}

	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;



	return 0;
}