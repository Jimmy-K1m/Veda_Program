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
		printf("1. �Է�\n");
		printf("2. ���\n");
		printf("3. �˻�\n");
		printf("9. ����\n");
		printf("���� --> ");

		scanf("%d", &menuNo);

		switch (menuNo) {
		case 1:
		{
			scoreEnter(score); // �����Է�
			break;
		}
		case 2:
		{
			scorePrint(score); // �������
			break;
		}
		case 3:
		{
			printf("%d\n", scoreSearch (px, score)); // ���� �˻� : ��ȣ
			break;
		}
		case 9:
		{
			printf("���Ḧ �����ϼ̽��ϴ�!\n");
			break;
		}
		default: {
			printf("�ٸ� ��ȣ�� �������ּ���\n");
		}
		}
	} while (menuNo != 9);
	return 0;
}
