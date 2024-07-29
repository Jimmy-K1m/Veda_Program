#include <iostream>
#include <string>
using namespace std;
#include "employee.h"

int _______main(void)
{
	// 사원 객체 생성
	Employee* emp[] = {
		new Regular("이제훈", 10000, 800),
		new Regular("김수현", 10001, 950),
		new Regular("김민기", 10002, 780),
		new Temporal("정현진", 10005, 15, 20)
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

// 임시직 사원은 일당 * 작업일수 

// 임시직

// 별도의 관리자 클래스

/*
Employee emp[] = {
		Regular("이제훈", 10000, 500),
		Regular("김수현", 10001, 950),
		Regular("김민기", 10002, 780),
		Temporal("정현진", 10005, 15, 20)
	};

	// 이번 달에 지불해야 할 급여의 정보
	for (int i = 0; i < 4; i++)
		emp[i].showSalary();

	// 이번 달에 지불해야 할 급여의 총합
	int totalSalary = 0;
	for (int i = 0; i < 4; i++)
		totalSalary += emp[i].getPay();

	cout << "급여 총합 : " << totalSalary << endl;

	return 0;
*/