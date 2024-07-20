#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*

int main() {
	FILE* fp;

	typedef struct type {
		int num;
		double dnum;
		char string[80];
	} TYPE;

	TYPE arr = { 10, 1.12345, "hello" };

	if ((fp = fopen("memo.txt", "w")) == NULL)
	{
		fprintf(stderr, "file not found\n");
		return 1;
	}

	fprintf(fp, "%d %lf %s", arr.num, arr.dnum, arr.string);

	fclose(fp);

	return 0;
}

*/

int main() {
	FILE* fp;

	typedef struct type {
		int num;
		double dnum;
		char string[80];
	} TYPE;

	TYPE arr = { 1, 1.12345, "hello" };

	if ((fp = fopen("memo.txt", "w")) == NULL)
	{
		fprintf(stderr, "file not found\n");
		return 1;
	}

	fprintf(fp, "%d %lf %s", arr.num, arr.dnum, arr.string);

	fclose(fp);

	TYPE arr1;

	if ((fp = fopen("memo.txt", "r")) == NULL)
	{
		fprintf(stderr, "file not found\n");
		return 1;
	}

	fscanf(fp, "%d %lf %s", &arr1.num, &arr1.dnum, arr1.string);
	printf("%d %lf %s", arr1.num, arr1.dnum, arr1.string);
	fclose(fp);

	return 0;
}