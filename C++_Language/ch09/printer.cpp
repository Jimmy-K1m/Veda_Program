#include "printer.h"
#include <iostream>

using namespace std;

Printer::Printer(string model, string manufacturer, int printedCount, int availableCount) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->printedCount = printedCount;
	this->availableCount = availableCount;
}

Ink::Ink(string model, string manufacturer, int printedCount, int availableCount, int availableInk) : Printer(model, manufacturer, printedCount, availableCount)
{
	this->availableInk = availableInk;
	cout << "잉크젯: " << this->model << ", " << this->manufacturer << ", 남은 종이 " << this->availableCount << " 남은 잉크 " << this->availableInk << endl;
}

void Ink::print(int pages) {

	if (pages > this->availableCount)
	{
		cout << "용지가 부족하여 프린트할 수 없습니다" << endl;
	}
	else {
		this->printedCount += pages;
		this->availableCount -= pages;
		this->availableInk -= pages;
		cout << "프린트하였습니다."<< endl;
	}
}
void Ink::show() {
	cout << "잉크젯: " << this->model << ", " << this->manufacturer << ", 남은 종이 " << this->availableCount << " 남은 잉크 " << this->availableInk << endl;
}
Laser::Laser(string model, string manufacturer, int printedCount, int availableCount, int availableToner) : Printer(model,manufacturer,printedCount,availableCount)

{

	this->availableToner = availableToner;
	cout << "레이저 : " << this->model << " , " << this->manufacturer << " , 남은 종이 " << this->availableCount << " 남은 토너 " << this->availableToner << endl;
}

void Laser::print(int pages) {
	if (pages > this->availableCount)
	{
		cout << "용지가 부족하여 프린트할 수 없습니다" << endl;
	}
	else {
		this->printedCount += pages;
		this->availableCount -= pages;
		this->availableToner -= pages;
		cout << "프린트하였습니다." << endl;
	}
}
void Laser::show() {
	cout << "레이저 : " << this->model << " , " << this->manufacturer << " , 남은 종이 " << this->availableCount << " 남은 토너 " << this->availableToner<<endl;
}
