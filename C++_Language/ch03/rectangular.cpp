#include "rectangular.h"
#include <iostream>
using namespace std;
//using namespace Rectangular;


	Rectangular::Rectangular() { width = 0; height = 0; };
	Rectangular::Rectangular(int a, int b) { width = a; height = b; };
	Rectangular::Rectangular(int a) { width = a; height = a; };
	Rectangular::~Rectangular() { cout << "¿ø¼Ò¸ê" << width << " " << height << endl; };

	bool Rectangular::isSquare()
	{
		/*
		if (width == height) return 1;
		else return 0;
		*/
		return (width == height);
	};

	double Rectangular::getArea() { return width * height; }

