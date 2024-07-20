#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main()
{

	struct link* HEAD, * TAIL, *temp;
	HEAD = TAIL = NULL;


	while (1)
	{
		temp = (struct link*)malloc(sizeof(struct link));
		if (temp == NULL)
		{
			printf("�޸� �Ҵ� ����\n");
			exit(1);
		}

		printf(" ID : ");
		scanf("%d", &temp->id); getchar();
		if (temp->id == -1)
			break;

		printf("NAME : ");
		fgets(temp->bookname, 30, stdin); // bookname�� �迭(�������̹Ƿ�) �ּ� �Ѱ��ִ� ��.
		temp->bookname[strlen(temp->bookname) - 1] = '\0';
		temp->next = NULL;

		if (HEAD == NULL) // ù��° ���
		{
			HEAD = temp;
			TAIL = temp;
		}
		else { // ù��° ��尡 �ƴ� ���
			TAIL-> next = temp; // ���� list�� ���� ���� �����
			TAIL = temp; // tail�� ���������� ������� ��带 pointing�ϰ� �ϱ�
		}
	}

	temp = HEAD;
	// ��ü ��� ���
	while(temp != NULL ){// temp�� tail�� next�� �������� �� �̴� ���� �ٴٶ����� �ǹ���. 
		printf("id: %d, name: %s\n", temp->id, temp->bookname);
		temp = temp->next; // temp�� �̵��ϱ� ���ؼ� next���� Ȱ���ؾ���.
	}
	
	// �˻�
	printf("Please enter which book do you want to find out\n");
	char temp_name[30];
	fgets(temp_name, 30,stdin);
	temp_name[strlen(temp_name) - 1] = '\0';

	temp = HEAD; // temp �ʱ�ȭ

	while (temp != NULL)
	{
		if (!strcmp(temp->bookname, temp_name))
		{
			printf("name : %s , id : %d\n", temp->bookname, temp->id);
			break;
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("No book that you want to find out\n");
	}
	// ����
	strcpy(temp_name, "");
	printf("Please enter which book do you want to eliminate\n");
	fgets(temp_name, 30, stdin);
	temp_name[strlen(temp_name) - 1] = '\0';

	struct link* prev = HEAD;
	temp = HEAD; // temp �ʱ�ȭ
	while (temp != NULL)
	{
		if (!strcmp(temp->bookname, temp_name)&& temp == HEAD)// ù��° ��尡 ������ ���
		{
			HEAD = temp->next;
			if (HEAD == NULL)
			{
				TAIL = NULL;
			}
			free(temp);
			break;
		}

		if (!strcmp(temp->bookname, temp_name) && temp != HEAD && temp != TAIL) // �߰� ��尡 ������ ���
		{
			prev->next = temp->next;
			free(temp);
			break;

		}
		if (!strcmp(temp->bookname, temp_name) && temp == TAIL)
		{
			prev->next = NULL;
			TAIL = prev;
			free(temp);
			break;
		}
			//tail�� ������ ��� null �ʱ�ȭ�� �ؾ���.
	
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("No book that you want to eliminate\n");
	}
	temp = HEAD;

	while (temp != NULL) {// temp�� tail�� next�� �������� �� �̴� ���� �ٴٶ����� �ǹ���. 
		printf("id: %d, name: %s\n", temp->id, temp->bookname);
		temp = temp->next; // temp�� �̵��ϱ� ���ؼ� next���� Ȱ���ؾ���.
	}
	
	temp = HEAD;
	prev = HEAD;
	// linkedlist ��ü ����
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	
	

	return 0;
}