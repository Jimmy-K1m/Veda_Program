#include <iostream>

using namespace std;

int __main() {
	int* p;

	p = new int;

	if (!p) {
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�";
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

	delete [] ptr; // ptr �߸� ������ �� �ֱ� ������ ptr�� NULL �� ó���ؾ���
	ptr = NULL;
	
	return 0;
}