
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int main() {

	printf("���ڸ� �Է����ּ���\n");
	int a;

	scanf("%d", &a);


	if (a % 2 == 0)
	{
		printf("¦���Դϴ�");
	}
	else
	{
		printf("Ȧ���Դϴ�");
	}

	return 0;
}
*/
/*
int main() {

	printf("���̸� �Է����ּ���\n");
	int age;

	scanf("%d", &age);


	if ((age>=0 && age <= 6)|| age >=65)
	{
		printf("�����Դϴ�");
	}
	else if (age >= 7 && age <= 16)
	{
		printf("5000���Դϴ�");
	}
	else if (age >= 17 && age <= 23)
	{
		printf("10000���Դϴ�");
	}
	else if (age >= 24 && age <= 55)
	{
		printf("13000���Դϴ�");
	}
	else if (age >= 56 && age <= 64)
	{
		printf("7000���Դϴ�");
	}
	else {
		printf("�����Դϴ�");
	}
	return 0;
}
*/
/*
int main()
{	
	int a;
	int b;
	int c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	printf("%d, %d, %d", a, b, c);

	if (a > b)
	{
		if(a>c)
		{ 
			printf("a�� ���� ū ���Դϴ�\n");
			if(c>b)
			{

				printf("b�� ���� ���� ���Դϴ�\n");
			}
			else {

			}

		}
		else
		{
			printf("c�� ���� ū �� �Դϴ�\n");
			printf("b�� ���� ���� �� �Դϴ�\n");
		}


	}
	else
	{
		if (b > c)
		{
			printf("b�� ���� ū ���Դϴ�\n");
			if (c > a)
			{

				printf("a�� ���� ���� ���Դϴ�\n");
			}
			else {
				printf("c�� ���� ���� ���Դϴ�\n");
			}

		}
		else
		{
			printf("c�� ���� ū �� �Դϴ�\n");
			printf("a�� ���� ���� �� �Դϴ�\n");
		}
	}

	return 0;
}
*/

// if ���� ��ø�� ����.
// max, min ���� ���ؼ� ��밡��

/*
int main() {
	int a, b, c;

	int max;
	int min;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if (a > b) {
		max = a;
		min = b;
		if (c > max)
		{
			max = c;
		}
		if(c < min)
		{
			min = c;
		}
		
	}
	else {
		max = b;
		min = a;
		if (c > max)
		{
			max = c;
		}
		if(c < min)
		{
			min = c;
		}
	}

	
	return 0;

}
*/

