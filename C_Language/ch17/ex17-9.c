#include <stdio.h>

int main() {

	typedef struct member
	{
		int id;
		double height;

	}Member; // typedef로 시작하는 건 맨 마지막이 자료형 이름임.

	typedef unsigned char uchar;// 기존 자료형을 재정의.


	//typedef struct member Member;
	Member p;

	p.id = 123;
	p.height = 1.234;
	printf("%d, %lf\n", p.id, p.height);

	return 0;
}
