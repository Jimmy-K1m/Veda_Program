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


		if (ch == '\r' || ch == '\n') // ������� �������� enterŰ�� ���� ����ڰ� �ٸ�
			break;

		putchar(ch);
	}

	printf("\n");


	return 0;
}