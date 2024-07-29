#include <iostream>
#include <string>

using namespace std;

#include "colorpoint.h"
#include "point.h"



int _main() {
	/*
	ColorPoint cp;

	cp.setColor("Red");
	cp.set(10, 20);
	cp.showColorPoint();
	cp.showPoint();
	*/

	/*
	ColorPoint cp;
	ColorPoint *pDer = &cp;
	Point* pBase = pDer;

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
	*/

	ColorPoint cp;
	ColorPoint* pDer;
	Point* pBase = &cp;

	pBase->set(3, 4);
	pBase->showPoint();

	pDer = (ColorPoint*)pBase;
	pDer->setColor("Red");

	pDer->showColorPoint();

	return 0;
}