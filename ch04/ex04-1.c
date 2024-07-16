#include <stdio.h>

int main()
{
	/*
	double num = 10;
	printf("%.2lf\n", num / 3);
	*/

	int num = 10;
	float fnum = (float)num / 3;

	printf("%f\n", fnum);

	char* p;
	p = (char*)malloc(80);

	int* p_;
	p_ = (int*)malloc(80);


	short str[10];

	printf("%u\n", sizeof(str) /sizeof(str[0]));// sizeof str 로 해도 가능 연산자기 때문.
	char* p__;
	p__ = (char*)malloc(80);


	return 0;
}