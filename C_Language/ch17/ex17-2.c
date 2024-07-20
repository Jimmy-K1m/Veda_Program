#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "score.h"

// 검색 이름
// 삭제 이름

int main()
{
	int menuNo;
	//int score[5];


	struct score stScore[30]; // 포인터로 이미 쓴 거나 다름 없음

	int x = 0;
	int* px;
	int idx = 0;

	px = &x;
	do
	{
		printf("1. 입력\n");
		printf("2. 출력\n");
		printf("3. 검색\n");
		printf("4. 삭제\n");
		printf("9. 종료\n");
		printf("선택 --> ");

		scanf("%d", &menuNo); getchar(); // 숫자 입력 후 문자 입력시 포함할 것

		switch (menuNo) {
		case 1:
		{
			Enter(stScore, idx++); // 성적입력
			break;
		}
		case 2:
		{
			Print(stScore, idx); // 성적출력
			break;
		}
		case 3:
		{
			nameSearch(stScore); // 성적 검색 : 번호
			break;
		}
		case 4:
		{
			nameDelete(stScore);
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
