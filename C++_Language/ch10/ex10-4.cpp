#include <iostream>
#include <vector>

using namespace std;

int ____main() {
	vector<string> v(3);


	for (int i = 0; i < 3; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}


/*
v.push_back("Hello");
	v.push_back("Bye");
	v.push_back("Great");

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v[0] = 10;
	string n = v[2];
	v.at(2) = "Superb";

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}*/