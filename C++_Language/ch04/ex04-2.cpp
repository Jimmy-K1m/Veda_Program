#include <iostream>

using namespace std;

int __main() {
	int* p;

	p = new int;

	if (!p) {
		cout << "메모리를 할당할 수 없습니다";
		return 0;
	}

	*p = 5;
	int n = *p;
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;

	int* ptr = new int[5];

	for (int i = 0; i < 5; i++)
	{
		*(ptr + i) = i;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << *(ptr + i) << endl;
	}

	delete [] ptr; // ptr 잘못 접근할 수 있기 때문에 ptr을 NULL 값 처리해야함
	ptr = NULL;
	
	return 0;
}