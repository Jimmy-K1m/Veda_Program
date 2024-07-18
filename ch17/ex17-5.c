
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "doublylinked.h"

//doubly + 함수화


int main()
{
	int menuNo;
	struct link* HEAD, * TAIL;
	HEAD = TAIL = NULL;


	do
	{
		printf("1. 입력\n");
		printf("2. 출력\n");
		printf("3. 검색\n");
		printf("4. 삭제\n");
		printf("9. 종료\n");
		printf("선택 --> ");

		scanf("%d", &menuNo); getchar();

		switch (menuNo) {
		case 1:
		{
			Enter(&HEAD, &TAIL); // 입력 
			// 더블 포인터가 넘어가야함.
			break;
		}
		case 2:
		{
			Print(HEAD, TAIL); // 출력
			break;
		}
		case 3:
		{
			Search(HEAD, TAIL); // 검색 : bookname
			break;
		}
		case 4:
		{
			Delete(&HEAD, &TAIL); // 삭제 : bookname
		}
		case 9:
		{
			Destroy(&HEAD, &TAIL);
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
