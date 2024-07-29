#include <iostream>
#include "printer.h"

using namespace std;


int main() {
	
	char ch;
	//Ink(string model, string manufacturer, int printedCount, int availableCount, int availableInk);
	cout << "현재 작동 중인 2 대의 프린터는 아래와 같다." << endl;
	Ink p1 = Ink("Officjet V40", "HP", 0, 5, 10);
	Laser p2 = Laser("SCX-6x45", "삼성전자", 0 , 3, 20);

	int a, b;

	while (1)
	{
		cout << '\n' << '\n';
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> a >> b;

		if (a == 1)
		{
			p1.print(b);
			p1.show();
			cout << "계속 프린트 하시겠습니까(y/n)";
			cin >> ch;

			if (ch == 'y')
			{
				continue;
			}
			else {
				break;
			}
		}
		else if (a == 2)
		{

			p2.print(b);
			p2.show();
			cout << "계속 프린트 하시겠습니까(y/n)";
			cin >> ch;

			if (ch == 'y')
			{
				continue;
			}
			else {
				break;
			}
		}
		else
		{
			cout << "다시 입력하세요" << endl;
		}

		

	}


	return 0;
}