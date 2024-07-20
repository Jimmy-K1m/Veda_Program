
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int main() {

	printf("숫자를 입력해주세요\n");
	int a;

	scanf("%d", &a);


	if (a % 2 == 0)
	{
		printf("짝수입니다");
	}
	else
	{
		printf("홀수입니다");
	}

	return 0;
}
*/
/*
int main() {

	printf("나이를 입력해주세요\n");
	int age;

	scanf("%d", &age);


	if ((age>=0 && age <= 6)|| age >=65)
	{
		printf("무료입니다");
	}
	else if (age >= 7 && age <= 16)
	{
		printf("5000원입니다");
	}
	else if (age >= 17 && age <= 23)
	{
		printf("10000원입니다");
	}
	else if (age >= 24 && age <= 55)
	{
		printf("13000원입니다");
	}
	else if (age >= 56 && age <= 64)
	{
		printf("7000원입니다");
	}
	else {
		printf("무료입니다");
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
			printf("a가 가장 큰 수입니다\n");
			if(c>b)
			{

				printf("b가 가장 작은 수입니다\n");
			}
			else {

			}

		}
		else
		{
			printf("c가 가장 큰 수 입니다\n");
			printf("b가 가장 작은 수 입니다\n");
		}


	}
	else
	{
		if (b > c)
		{
			printf("b가 가장 큰 수입니다\n");
			if (c > a)
			{

				printf("a가 가장 작은 수입니다\n");
			}
			else {
				printf("c가 가장 작은 수입니다\n");
			}

		}
		else
		{
			printf("c가 가장 큰 수 입니다\n");
			printf("a가 가장 작은 수 입니다\n");
		}
	}

	return 0;
}
*/

// if 문의 중첩을 쓴다.
// max, min 값을 정해서 사용가능

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

