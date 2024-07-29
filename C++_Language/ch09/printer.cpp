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
	cout << "��ũ��: " << this->model << ", " << this->manufacturer << ", ���� ���� " << this->availableCount << " ���� ��ũ " << this->availableInk << endl;
}

void Ink::print(int pages) {

	if (pages > this->availableCount)
	{
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;
	}
	else {
		this->printedCount += pages;
		this->availableCount -= pages;
		this->availableInk -= pages;
		cout << "����Ʈ�Ͽ����ϴ�."<< endl;
	}
}
void Ink::show() {
	cout << "��ũ��: " << this->model << ", " << this->manufacturer << ", ���� ���� " << this->availableCount << " ���� ��ũ " << this->availableInk << endl;
}
Laser::Laser(string model, string manufacturer, int printedCount, int availableCount, int availableToner) : Printer(model,manufacturer,printedCount,availableCount)

{

	this->availableToner = availableToner;
	cout << "������ : " << this->model << " , " << this->manufacturer << " , ���� ���� " << this->availableCount << " ���� ��� " << this->availableToner << endl;
}

void Laser::print(int pages) {
	if (pages > this->availableCount)
	{
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;
	}
	else {
		this->printedCount += pages;
		this->availableCount -= pages;
		this->availableToner -= pages;
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
}
void Laser::show() {
	cout << "������ : " << this->model << " , " << this->manufacturer << " , ���� ���� " << this->availableCount << " ���� ��� " << this->availableToner<<endl;
}
