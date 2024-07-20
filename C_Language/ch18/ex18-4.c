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

	TYPE arr[5] = {{20, 1.11111, "good"}, {30, 1.11111, "bad"}, {40, 1.11111, "fine"}};

	if ((fp = fopen("memo.txt", "wb")) == NULL)
	{
		fprintf(stderr, "file not found\n");
		return 1;
	}



	fwrite(&arr, sizeof(arr), 1, fp);

	fclose(fp);

	TYPE arr1;

	if ((fp = fopen("memo.txt", "r")) == NULL)
	{
		fprintf(stderr, "file not found\n");
		return 1;
	}

	while (!feof(fp))
	{
		fread(&arr1, sizeof(arr1), 1, fp);
		//if (arr1.num == 0)
		//	break;
		printf("%d %lf %s\n", arr1.num, arr1.dnum, arr1.string);
	}
	fclose(fp);

	return 0;
}