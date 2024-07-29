#pragma once
#include <string>

using namespace std;

class Printer {

protected:
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
	
public:
	Printer();
	Printer(string model, string manufacturer, int printedCount, int availableCount);
	virtual void print(int pages) = 0;
	virtual void show() = 0;

};

class Ink : public Printer{
protected:
	int availableInk;
public:
	Ink() {};
	Ink(string model, string manufacturer, int printedCount, int availableCount, int availableInk);
	virtual void print(int pages);
	virtual void show();

};

class Laser : public Printer {
protected:
	int availableToner;
public:
	Laser() {};
	Laser(string model, string manufacturer, int printedCount, int availableCount, int availableToner);
	virtual void print(int pages);
	virtual void show();
};