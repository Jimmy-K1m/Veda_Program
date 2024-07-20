#include <stdio.h>

int main()
{
	char ch = 'a';
	int inum = 10;
	float fnum = 1.234;
	void* vp[3];

	//malloc(), memcpy() // 기본형이 void*이다 어떤 형식이든 받을 수 있다. 원형 함수는 void로 되는 경우가 많다.

	vp[0] = &ch;
	//printf("%c\n", *vp); 불완전함
	printf("%c\n", *((char*)vp[0])); // char*은 형식

	vp[1] = &inum;
	printf("%d\n", *((int*)vp[1]));

	vp[2] = &fnum;
	printf("%.3f\n", *((float*)vp[2]));

	return 0;
}