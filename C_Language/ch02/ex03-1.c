#include <stdio.h>

int main(void)
{
	int num = 100;
	float fnum = 2.5;
	double dnum = 34.789654087;
	char ch = 65;

	printf("%d\t,%d\t,%d\t,%d\n", sizeof(int), sizeof(float), sizeof(double), sizeof(char));

	printf("New One is %d\t,%d\t,%d\t\n", sizeof(short), sizeof(long), sizeof(long double));

	printf("%c, %f, %lf, %c\n", num, fnum, dnum, ch); 

	//num 

	return 0;
}