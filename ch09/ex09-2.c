#include <stdio.h>

int main()
{
	float fnum[5] = { 1.2, 2.2, 3.4, 5.5, 6.6 };
	float* fp;

	fp = fnum; // fp와 fnum 모두 주소를 나타냄

	for (int i = 0; i < 5; i++)
	{
		printf("%f\n", fnum[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%f\n", *(fnum++));
	}
	printf("\n");

	fp = fnum;

	for (int i = 0; i < 5; i++)
	{
		printf("%f\n", fp[i]);
	}

	return 0;
}