#include <iostream>
#include <string>
using namespace std;
#include "employee.h"

int _______main(void)
{
	// ��� ��ü ����
	Employee* emp[] = {
		new Regular("������", 10000, 800),
		new Regular("�����", 10001, 950),
		new Regular("��α�", 10002, 780),
		new Temporal("������", 10005, 15, 20)
	};

	EmployeeManager* p = new EmployeeManager;
	for (int i = 0; i < 4; i++)
	{
		p->addEmployee(emp[i]);
	}
	p->showAllSalary();
	p->showTotalSalary();
	
	for (int i = 0; i < 4; i++)
	{
		delete emp[i];
	}

	delete p;
	return 0;
}

// �ӽ��� ����� �ϴ� * �۾��ϼ� 

// �ӽ���

// ������ ������ Ŭ����

/*
Employee emp[] = {
		Regular("������", 10000, 500),
		Regular("�����", 10001, 950),
		Regular("��α�", 10002, 780),
		Temporal("������", 10005, 15, 20)
	};

	// �̹� �޿� �����ؾ� �� �޿��� ����
	for (int i = 0; i < 4; i++)
		emp[i].showSalary();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	int totalSalary = 0;
	for (int i = 0; i < 4; i++)
		totalSalary += emp[i].getPay();

	cout << "�޿� ���� : " << totalSalary << endl;

	return 0;
*/