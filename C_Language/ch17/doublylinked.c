
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "doublylinked.h"

void Enter(struct link** Head, struct link** Tail)
{
	struct link* temp = (struct link*)malloc(sizeof(struct link));
	if (temp == NULL)
	{
		printf("메모리 할당 실패\n");
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
	fgets(temp->bookname, 30, stdin); // bookname이 배열(포인터이므로) 주소 넘겨주는 것.
	
	temp->bookname[strlen(temp->bookname) - 1] = '\0';
	temp->next = NULL;
	temp->before = NULL;
	struct link* back;

	if (*Head == NULL) // 첫번째 노드
	{
		*Head = temp;
		*Tail = temp;
	}
	else { // 첫번째 노드가 아닌 경우
		
		(*Tail) -> next = temp; // 기존 list와 연결 관계 만들기
		temp->before = *Tail;
		*Tail = temp; // tail이 최종적으로 만들어진 노드를 pointing하게 하기

	}
}
void Print(struct link* Head, struct link* Tail)
{
	
	struct link* temp;

	temp = Head; // temp 초기화

	//printf("%p", temp);
	while (temp != NULL)
	{
		printf("id: %d, name: %s\n", temp->id, temp->bookname);
		temp = temp->next; // temp가 이동하기 위해서 next값을 활용해야함.
	}
	
	return;
}
void Search(struct link* Head, struct link* Tail)
{
	printf("Please enter which book do you want to find out\n");
	char temp_name[30];
	fgets(temp_name, 30, stdin);
	temp_name[strlen(temp_name) - 1] = '\0';

	struct link* temp =  Head; // temp 초기화

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
		if (!strcmp(temp->bookname, temp_name) && temp == *Head)// 첫번째 노드가 삭제될 경우
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

		if (!strcmp(temp->bookname, temp_name) && temp != *Head && temp != *Tail) // 중간 노드가 삭제될 경우
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
		//tail이 삭제될 경우 null 초기화도 해야함.

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