#include "man.h"
#include <string>


Man::Man() {
	cout << "Man �⺻ ������ �Լ�" << endl;
}

Man::Man(const string& name, int age) 
	: Human(name, age) // �ʱ�ȭ Human �����ڿ��� ���� �� Man �����ڰ� �̾����.
{

	cout << "Man ������ �Լ�(�Ű�����)" << endl;
	//this->name = name;
	//this->age = age;
	
}

Man::~Man() {
	cout << "Man �Ҹ��� �Լ�" << endl;
}

void Man::show() {
	Human::show();
	cout << "����" << endl;
}