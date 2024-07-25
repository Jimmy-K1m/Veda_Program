#pragma once
#include <string>
#include "person_.h"

class Family {
	Person* p;
	int size;

public:
	Family(string name, int size);
	void setName(int x, string name);
	void show();
	~Family();
};