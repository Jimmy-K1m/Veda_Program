
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "doublylinked.h"

void Enter(struct link** Head, struct link** Tail)
{
	struct link* temp = (struct link*)malloc(sizeof(struct link));
	if (temp == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	printf(" ID : ");
	scanf("%d", &temp->id); getchar();

	if (temp->id == -1)
	{
		printf("Stop");
		return;
	}

	printf("NAME : ");
	fgets(temp->bookname, 30, stdin); // bookname�� �迭(�������̹Ƿ�) �ּ� �Ѱ��ִ� ��.
	
	temp->bookname[strlen(temp->bookname) - 1] = '\0';
	temp->next = NULL;
	temp->before = NULL;
	struct link* back;

	if (*Head == NULL) // ù��° ���
	{
		*Head = temp;
		*Tail = temp;
	}
	else { // ù��° ��尡 �ƴ� ���
		
		(*Tail) -> next = temp; // ���� list�� ���� ���� �����
		temp->before = *Tail;
		*Tail = temp; // tail�� ���������� ������� ��带 pointing�ϰ� �ϱ�

	}
}
void Print(struct link* Head, struct link* Tail)
{
	
	struct link* temp;

	temp = Head; // temp �ʱ�ȭ

	//printf("%p", temp);
	while (temp != NULL)
	{
		printf("id: %d, name: %s\n", temp->id, temp->bookname);
		temp = temp->next; // temp�� �̵��ϱ� ���ؼ� next���� Ȱ���ؾ���.
	}
	
	return;
}
void Search(struct link* Head, struct link* Tail)
{
	printf("Please enter which book do you want to find out\n");
	char temp_name[30];
	fgets(temp_name, 30, stdin);
	temp_name[strlen(temp_name) - 1] = '\0';

	struct link* temp =  Head; // temp �ʱ�ȭ

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

}

void Delete(struct link** Head, struct link** Tail)
{
	struct link* temp = *Head;
	char temp_name[30];
	printf("Please enter which book do you want to eliminate\n");
	fgets(temp_name, 30, stdin);
	temp_name[strlen(temp_name) - 1] = '\0';

	struct link* prev = *Head;
	temp = *Head;

	while (temp != NULL)
	{
		if (!strcmp(temp->bookname, temp_name) && temp == *Head)// ù��° ��尡 ������ ���
		{
			*Head = temp->next;
			(*Head)->before = NULL;
			if (*Head == NULL)
			{
				*Tail = NULL;
			}
			free(temp);
			break;
		}

		if (!strcmp(temp->bookname, temp_name) && temp != *Head && temp != *Tail) // �߰� ��尡 ������ ���
		{
			prev->next = temp->next;
			temp->next->before = temp->before;
			free(temp);
			break;

		}
		if (!strcmp(temp->bookname, temp_name) && temp == *Tail)
		{
			prev->next = NULL;
			*Tail = prev;
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
	return;
}

void Destroy(struct link** Head, struct link** Tail)
{
	struct link* temp = *Head;
	struct link* prev = *Head;
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}
}