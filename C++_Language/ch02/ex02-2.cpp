#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

	int iter = 0;
	int win_sum = 0;
	int lose_sum = 0;


	while (iter < 3) {
		cout << "-----���������� ���� ����-----"<< endl;
		cout << "0 : ���� 1: ���� 2: ��" << endl;
		int user;
		cin >> user;

		int computer;
		computer = rand() % 3;

		cout <<"computer: " << computer << endl;
	

		if ((user == 0 && computer == 2) || (user == 1 && computer == 0) || (user == 2 && computer == 1))
		{
			cout << "����� �̰���ϴ�" << endl;
			win_sum++;
		}
		else if ((user == 0 && computer == 0) || (user == 1 && computer == 1) || (user == 2 && computer == 2))
		{
			cout << "�����ϴ�" << endl;
		}
		else {
			cout << "����� �����ϴ�" << endl;
			lose_sum++;
		}
		iter++;
	}

	cout << "����� " << win_sum << "�� �̱��" << lose_sum << "�� �����ϴ�" << endl;

	return 0;
}
