#include <iostream>
#include <string>

using namespace std;
int main()
{
	int score[10];
	cout << "�Է� ���� ���� : ";
	for (int i = 0; i < 10; i++)
	{
		cin >> score[i];
	}
	cout << "�հ� : ";
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += score[i];
	}
	cout << sum;
	cout << "��� : " << sum / 10;

	return 0;
}
/*

int main_()
{
	struct CUSTOMER {
		string name;
		int age;
		char gender;
	};

	CUSTOMER customer[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> customer[i].name >> customer[i].age >> customer[i].gender;//
		//getline(cin, customer[i].name);
		//cin >>  customer[i].age >> customer[i].gender;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << customer[i].name << customer[i].age << customer[i].gender;//
		//getline(cin, customer[i].name);
		//cin >>  customer[i].age >> customer[i].gender;
	}

	return 0;

}
*/