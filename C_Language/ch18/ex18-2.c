#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	char ch;
	while (1)
	{
		ch = getche(); // ch = getchar();

		if (ch == EOF)
			break;


		if (ch == '\r' || ch == '\n') // 윈도우와 리눅스의 enter키에 대한 제어문자가 다름
			break;

		putchar(ch);
	}

	printf("\n");


	return 0;
}