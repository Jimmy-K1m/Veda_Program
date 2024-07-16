#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menuArray.h"


int main()
{
	int menuNo;
	int score[5];
	int x = 0;
	int* px;

	px = &x;
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
			scoreEnter(score); // 성적입력
			break;
		}
		case 2:
		{
			scorePrint(score); // 성적출력
			break;
		}
		case 3:
		{
			printf("%d\n", scoreSearch (px, score)); // 성적 검색 : 번호
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
	} while (menuNo != 9);
	return 0;
}
