#include <iostream>

using namespace std;

class BaseIO {
public:
	int mode;
};

class In : virtual public BaseIO {
public:
	int readPos;
};

class Out : virtual public BaseIO {
public:
	int writePos;
};

class InOut : public In, public Out {
public:
	bool safe;
};


int ____main() {
	InOut inobj;
	inobj.readPos = 10;
	inobj.writePos = 20;
	inobj.safe = true;
	inobj.mode = 5; // 모호성이 없음.

	cout << inobj.mode << endl;

	return 0;
}