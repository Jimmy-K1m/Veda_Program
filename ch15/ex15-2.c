
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add(int a, int b);
void sub(int a, int b);
void mult(int a, int b);
void div(int a, int b);

int main()
{
	void (*fp[4])(int, int); //�Լ��� ���� �� �ִ� ������ �ʱ�ȭ, Ÿ���� ������ ������.


	// void (*fp[4])(int, int) = {add, sub, mult, div} ����

	// switch case ������ �� ������ �ڵ尡 ����.
	fp[0] = add; 
	*(fp + 1) = sub;
	fp[2] = mult;
	*(fp + 3) = div;
	//fp[0](10, 50);
	
	printf("type down numbers among 0~3 \n");

	while (1)
	{
		int i;
		scanf("%d", &i);
		if (i == -1)
			break;
		else
		{
			fp[i](50, 10);
		}
	}
	

	return 0;
}

void add(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

void sub(int a, int b)
{
	printf("%d - %d = %d\n", a, b, a - b);
}

void mult(int a, int b)
{
	
	printf("%d * %d = %d\n", a, b, a * b);
}

void div(int a, int b)
{
	if (b == 0)
	{
		printf("type down other numbers");
	}
	else {
		printf("%d / %d = %d\n", a, b, a / b);
	}
}