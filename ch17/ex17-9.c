#include <stdio.h>

int main() {

	typedef struct member
	{
		int id;
		double height;

	}Member; // typedef�� �����ϴ� �� �� �������� �ڷ��� �̸���.

	typedef unsigned char uchar;// ���� �ڷ����� ������.


	//typedef struct member Member;
	Member p;

	p.id = 123;
	p.height = 1.234;
	printf("%d, %lf\n", p.id, p.height);

	return 0;
}
