#include <iostream>
using namespace std;
/*
int main()
{
	cout << "너비를 입력하세요>>";

	int width;
	cin >> width;

	cout << "높이를 입력하세요>>";

	int height;
	cin >> height;

	int area = width * height;
	cout << "면적은 " << area << "\n";

	return 0;
}
*/
int main()
{
	cout << "너비와 높이를 입력하세요>>";

	int width, height;
	cin >> width >> height; // 구분자가 공백이다

	int area = width * height;
	cout << "면적은 " << area<< endl;

	return 0;
}