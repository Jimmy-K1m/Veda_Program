#include <iostream>
#include "printer.h"

using namespace std;


int main() {
	
	char ch;
	//Ink(string model, string manufacturer, int printedCount, int availableCount, int availableInk);
	cout << "���� �۵� ���� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	Ink p1 = Ink("Officjet V40", "HP", 0, 5, 10);
	Laser p2 = Laser("SCX-6x45", "�Ｚ����", 0 , 3, 20);

	int a, b;

	while (1)
	{
		cout << '\n' << '\n';
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> a >> b;

		if (a == 1)
		{
			p1.print(b);
			p1.show();
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)";
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
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)";
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
			cout << "�ٽ� �Է��ϼ���" << endl;
		}

		

	}


	return 0;
}