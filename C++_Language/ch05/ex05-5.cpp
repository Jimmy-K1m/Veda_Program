#include<iostream>

using namespace std;

char& find(char s[], int index) {
	return s[index];
}

int _____main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S'; // name[0] = 'S'¿Í °°À½
	cout << name << endl;

	char& ref = find(name, 2);
	ref = 't';

	cout << name << endl;


	return 0;

}