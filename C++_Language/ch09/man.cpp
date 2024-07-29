#include "man.h"
#include <string>


Man::Man() {
	cout << "Man 기본 생성자 함수" << endl;
}

Man::Man(const string& name, int age) 
	: Human(name, age) // 초기화 Human 생성자에서 진행 후 Man 생성자가 이어받음.
{

	cout << "Man 생성자 함수(매개변수)" << endl;
	//this->name = name;
	//this->age = age;
	
}

Man::~Man() {
	cout << "Man 소멸자 함수" << endl;
}

void Man::show() {
	Human::show();
	cout << "남성" << endl;
}