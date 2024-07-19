#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	
	FILE* fp;
	fp = fopen("memo.txt", "r");

	if ( fp == NULL) //r,w 모드, +모드도 있지만 쓸 필요가 없을 것 같음. rt는 텍스트 rb는 binary
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