#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "score.h"

// �˻� �̸�
// ���� �̸�

int main()
{
	int menuNo;
	//int score[5];


	struct score stScore[30]; // �����ͷ� �̹� �� �ų� �ٸ� ����

	int x = 0;
	int* px;
	int idx = 0;

	px = &x;
	do
	{
		printf("1. �Է�\n");
		printf("2. ���\n");
		printf("3. �˻�\n");
		printf("4. ����\n");
		printf("9. ����\n");
		printf("���� --> ");

		scanf("%d", &menuNo); getchar(); // ���� �Է� �� ���� �Է½� ������ ��

		switch (menuNo) {
		case 1:
		{
			Enter(stScore, idx++); // �����Է�
			break;
		}
		case 2:
		{
			Print(stScore, idx); // �������
			break;
		}
		case 3:
		{
			nameSearch(stScore); // ���� �˻� : ��ȣ
			break;
		}
		case 4:
		{
			nameDelete(stScore);
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
