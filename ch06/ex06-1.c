#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int main()
{
	char ch;


	while (1)
	{
		scanf("%c", &ch); getchar();

		if (ch == 'q')
			break;
		else
			printf("Input letter is %c\n", ch);
	}

	return 0;
}
*/


/*


int main()
{
	int count = 0;
	int sum = 0;

	for(int i = 1; i < 1000 ; i++)
	{
		if (i % 3 == 0)
		{
			count++;
			sum += i;
		}
	
	}

	printf("count is %d\tsum is %d \n", count, sum);

return 0;
}
*/

// 입력 /출력 /검색 메뉴 프로그램 - do~whlie(menu.c)

/*
int main()
{
	int menuNo;
	
	do
	{
		printf("1. 입력\n");
		printf("2. 출력\n");
		printf("3. 검색\n");
		printf("9. 종료\n");
		printf("선택 --> ");

		scanf("%d", &menuNo);

		switch (menuNo) {
		case 1:
		{
			printf("입력을 선택하셨습니다!\n");
			break;
		}
		case 2:
		{
			printf("출력을 선택하셨습니다!\n");
			break;
		}
		case 3:
		{
			printf("검색을 선택하셨습니다!\n");
			break;
		}
		case 9:
		{
			printf("종료를 선택하셨습니다!\n");
			break;
		}
		default: {
			printf("다른 번호를 선택해주세요\n");
		}
		}
	}while (menuNo!=9);
	return 0;
}



*/
/*
int main()
{
	for (int i = 0; i <= 5; i= i+2)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
*/
/*
int main()
{
	int cnt = 0;
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			for (int k = 0; k <= 10; k++)
			{
				if ((5 * i + 3 * j + 2 * k) == 81)
				{
					printf("2's %d\t 3's %d\t 5's %d \n", k, j, i);
					cnt++;
				}
			}
		}
	}

	printf("%d", cnt);
	return 0;
}
*/
/*

int main()
{
	int cnt = 0;
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			int k = (81 - 5 * i - 3 * j);
			if (k% 2 == 0 && k <= 20)

			{
				printf("2's %d\t 3's %d\t 5's %d \n", k/2, j, i);
				cnt++;
			}
			if (i < 5)break;

		}
	}

	printf("%d", cnt);
	return 0;
}

*/


int main()
{
	int number;

	scanf("%d", &number);

	for (int i = 2; i <= number; i++)
	{
		if (number % i == 0 && i == number)
		{
			printf("소수입니다");
			break;
		}
		if (number % i == 0)
		{
			printf("소수가 아닙니다");
			break;
		}
		

	}
	
}

