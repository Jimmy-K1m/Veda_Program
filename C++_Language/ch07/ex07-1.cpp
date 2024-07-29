#include <iostream>

using namespace std;

class Rect;
bool equals(Rect r, Rect s);

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true; // width와 height를 자유롭게 접근
	else return false;
}

int _main() {
	Rect a(3, 4), b(3, 4);
	if (equals(a, b)) cout << "equals" << endl;
	else cout << "not equal" << endl;

	return 0;
}