#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 사원 객체의 속성 및 제어를 위한 클래스
class Employee
{
protected:
	string name;		// 사원 이름
	int empNumber;		// 사번
	//int total_salary;			// 월 급여

public:
	Employee() {};
	Employee(string name, int empNumber);
	//friend EmployeeManager;
	virtual int getPay() const; // 맨 마지막 const는 함수 안에서는 어떠한 변경 작업도 될 수 없음을 의미
	void showSalary() const;
	string getName() const;
}; // 정보를 변경하는 것이 아닌 정보를 조회할 때 const를 사용함 컴파일러에게 정확히 알려주는 쪽에 가까움


class Regular: public Employee
{
protected:
	int salary;			// 월 급여

public:
	Regular(string name, int empNumber, int salary);
	Regular() {};
	virtual int getPay() const;
}; 

class Temporal : public Employee
{
protected:
	int salary;			// 월 급여
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

//부모 클래스에서는 사원 이름 사번
// 정규직 Derived는 상속 받는 거 + 월급여
// 임시직 Derived는 하루 일당 + 근무일수
// 확인만 하는 형태
// 포인터 배열이라 동적 생성 human이랑 유사하게
#endif