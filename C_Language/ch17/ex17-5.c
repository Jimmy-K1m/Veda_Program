
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "doublylinked.h"

//doubly + �Լ�ȭ


int main()
{
	int menuNo;
	struct link* HEAD, * TAIL;
	HEAD = TAIL = NULL;


	do
	{
		printf("1. �Է�\n");
		printf("2. ���\n");
		printf("3. �˻�\n");
		printf("4. ����\n");
		printf("9. ����\n");
		printf("���� --> ");

		scanf("%d", &menuNo); getchar();

		switch (menuNo) {
		case 1:
		{
			Enter(&HEAD, &TAIL); // �Է� 
			// ���� �����Ͱ� �Ѿ����.
			break;
		}
		case 2:
		{
			Print(HEAD, TAIL); // ���
			break;
		}
		case 3:
		{
			Search(HEAD, TAIL); // �˻� : bookname
			break;
		}
		case 4:
		{
			Delete(&HEAD, &TAIL); // ���� : bookname
		}
		case 9:
		{
			Destroy(&HEAD, &TAIL);
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
