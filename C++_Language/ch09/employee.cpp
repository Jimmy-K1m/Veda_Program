#include "employee.h"
//#include <iostream>

// 사원 객체의 속성 및 제어를 위한 클래스
Employee::Employee(string name, int empNumber)
{
	this->name = name;
	this->empNumber = empNumber;
}

int Employee::getPay() const
{
	return 0;
}

void Employee::showSalary() const
{
	cout << "name : " << name;
	cout << "사번 : " << empNumber;
	cout << " 월 급여 : " << getPay() << endl << endl;
}

string Employee::getName() const
{
	return this->name;
}

Regular::Regular(string name, int empNumber, int salary) : Employee(name, empNumber)
{
	this->salary = salary;
	//this->total_salary = this->salary;
}
int Regular::getPay() const
{
	return salary;
}


Temporal::Temporal(string name, int empNumber, int salary, int day) : Employee(name, empNumber) {
	this->salary = salary;
	this->day = day;
	this->salary = (this->day) * (this->salary);
	//this->total_salary = (this->salary) * (this->day);
}

int Temporal::getPay() const
{
	return salary;
}

/*
class EmployeeManager {
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeManager();
	~EmployeeManager();
	void addEmployee(Employee* emp);
	void showAllSalary() const;
	void showTotalSalary() const;
};

*/
EmployeeManager::EmployeeManager()
{
	this->empNum = 0;
}
EmployeeManager::~EmployeeManager()
{

}
void EmployeeManager::addEmployee(Employee* emp)
{
	if (this->empNum >= 50) {
		cout << "더 이상 추가할 수 없습니다" << endl;
		return;
	}

	this->empList[this->empNum] = emp;
	this->empNum++;
}

void EmployeeManager::showAllSalary()
{
	int temp = 0;

	vector<Employee*>::iterator it;

	for (it = empList.begin(); it != empList.end(); it++)
	{
		(*it)->showSalary();
	}
	/*
	for (int i = 0; i < this->empNum; i++)
	{
		this-> empList[i]->showSalary();
	}
	*/
}
void EmployeeManager::showTotalSalary() {
	int temp = 0;

	vector<Employee*>::iterator it;
	for (it = empList.begin(); it != empList.end(); it++)
	{
		temp += (*it)->getPay();
	}
	cout << "Total salary is " << temp << endl;
	/*
	int temp = 0;
	for (int i = 0; i < this->empNum; i++)
	{
		temp += this->empList[i]->getPay();
	}
	cout << "Total salary is " << temp << endl;
	*/
}
