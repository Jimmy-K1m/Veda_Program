#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	
	FILE* fp;
	fp = fopen("memo.txt", "r");

	if ( fp == NULL) //r,w ���, +��嵵 ������ �� �ʿ䰡 ���� �� ����. rt�� �ؽ�Ʈ rb�� binary
	{
		fprintf(stderr, "memo.txt file not found\n");
		exit(1);
	}

	char ch;
	while (1)
	{
		ch = fgetc(fp);

		if (ch == EOF)
			break;

		putchar(ch);
	}
	
	printf("\n");
	fclose(fp);

	return 0;
}