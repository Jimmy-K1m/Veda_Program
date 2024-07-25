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
		cout << "-----가위바위보 게임 시작-----"<< endl;
		cout << "0 : 가위 1: 바위 2: 보" << endl;
		int user;
		cin >> user;

		int computer;
		computer = rand() % 3;

		cout <<"computer: " << computer << endl;
	

		if ((user == 0 && computer == 2) || (user == 1 && computer == 0) || (user == 2 && computer == 1))
		{
			cout << "당신이 이겼습니다" << endl;
			win_sum++;
		}
		else if ((user == 0 && computer == 0) || (user == 1 && computer == 1) || (user == 2 && computer == 2))
		{
			cout << "비겼습니다" << endl;
		}
		else {
			cout << "당신이 졌습니다" << endl;
			lose_sum++;
		}
		iter++;
	}

	cout << "당신은 " << win_sum << "번 이기고" << lose_sum << "번 졌습니다" << endl;

	return 0;
}
