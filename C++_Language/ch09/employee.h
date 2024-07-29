#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// ��� ��ü�� �Ӽ� �� ��� ���� Ŭ����
class Employee
{
protected:
	string name;		// ��� �̸�
	int empNumber;		// ���
	//int total_salary;			// �� �޿�

public:
	Employee() {};
	Employee(string name, int empNumber);
	//friend EmployeeManager;
	virtual int getPay() const; // �� ������ const�� �Լ� �ȿ����� ��� ���� �۾��� �� �� ������ �ǹ�
	void showSalary() const;
	string getName() const;
}; // ������ �����ϴ� ���� �ƴ� ������ ��ȸ�� �� const�� ����� �����Ϸ����� ��Ȯ�� �˷��ִ� �ʿ� �����


class Regular: public Employee
{
protected:
	int salary;			// �� �޿�

public:
	Regular(string name, int empNumber, int salary);
	Regular() {};
	virtual int getPay() const;
}; 

class Temporal : public Employee
{
protected:
	int salary;			// �� �޿�
	int day;
public:
	Temporal() {};
	Temporal(string name, int empNumber, int salary, int day);
	virtual int getPay() const;
};


class EmployeeManager {
private:
	//Employee* empList[50];
	vector<Employee* > empList;
	int empNum;

public:
	EmployeeManager();
	~EmployeeManager();
	void addEmployee(Employee* emp);
	void showAllSalary();
	void showTotalSalary();
};

//�θ� Ŭ���������� ��� �̸� ���
// ������ Derived�� ��� �޴� �� + ���޿�
// �ӽ��� Derived�� �Ϸ� �ϴ� + �ٹ��ϼ�
// Ȯ�θ� �ϴ� ����
// ������ �迭�̶� ���� ���� human�̶� �����ϰ�
#endif