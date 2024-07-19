// 링크드 리스트
// load 함수와 save 함수 만들 것.
// 실행하자마자 load 함수 사용
// save 함수는 

// 파일
// 한번 읽어올 때 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include "linked.h"
#define LANG 0

void load(struct link** Head, struct link** Tail);
void save(struct link* Head);

struct link {
	char bookname[30];
	int id;
	struct link* next;
};

int main()
{

	struct link* HEAD, * TAIL, * temp;
	HEAD = TAIL = NULL;
	FILE* fp;
	
	//load(&HEAD, &TAIL);
	while (1)
	{

#if LANG == 0
		printf("입력\n");


#else  
		printf("print\n");
#endif
		temp = (struct link*)malloc(sizeof(struct link));
		if (temp == NULL)
		{
			printf("메모리 할당 실패\n");
			exit(1);
		}

		printf(" ID : ");
		scanf("%d", &temp->id); getchar();
		if (temp->id == -1)
			break;

		printf("NAME : ");
		fgets(temp->bookname, 30, stdin); // bookname이 배열(포인터이므로) 주소 넘겨주는 것.
		temp->bookname[strlen(temp->bookname) - 1] = '\0';
		temp->next = NULL;

		if (HEAD == NULL) // 첫번째 노드
		{
			HEAD = temp;
			TAIL = temp;
		}
		else { // 첫번째 노드가 아닌 경우
			TAIL->next = temp; // 기존 list와 연결 관계 만들기
			TAIL = temp; // tail이 최종적으로 만들어진 노드를 pointing하게 하기
		}
	}

	temp = HEAD;
	// 전체 노드 출력
	while (temp != NULL) {// temp가 tail의 next를 가리켰을 때 이는 끝에 다다랐음을 의미함. 
		printf("id: %d, name: %s\n", temp->id, temp->bookname);
		temp = temp->next; // temp가 이동하기 위해서 next값을 활용해야함.
	}

	// 검색
	printf("Please enter which book do you want to find out\n");
	char temp_name[30];
	fgets(temp_name, 30, stdin);
	temp_name[strlen(temp_name) - 1] = '\0';

	temp = HEAD; // temp 초기화

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
	// 삭제
	strcpy(temp_name, "");
	printf("Please enter which book do you want to eliminate\n");
	fgets(temp_name, 30, stdin);
	temp_name[strlen(temp_name) - 1] = '\0';

	struct link* prev = HEAD;
	temp = HEAD; // temp 초기화
	while (temp != NULL)
	{
		if (!strcmp(temp->bookname, temp_name) && temp == HEAD)// 첫번째 노드가 삭제될 경우
		{
			HEAD = temp->next;
			if (HEAD == NULL)
			{
				TAIL = NULL;
			}
			free(temp);
			break;
		}

		if (!strcmp(temp->bookname, temp_name) && temp != HEAD && temp != TAIL) // 중간 노드가 삭제될 경우
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
		//tail이 삭제될 경우 null 초기화도 해야함.

		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("No book that you want to eliminate\n");
	}
	temp = HEAD;

	while (temp != NULL) {// temp가 tail의 next를 가리켰을 때 이는 끝에 다다랐음을 의미함. 
		printf("id: %d, name: %s\n", temp->id, temp->bookname);
		temp = temp->next; // temp가 이동하기 위해서 next값을 활용해야함.
	}

	temp = HEAD;
	prev = HEAD;
	// linkedlist 전체 삭제
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}

	//save(HEAD);

	return 0;
}


void load(struct link** Head, struct link** Tail) {
	FILE* fp;
	char tmp_bookname[30];
	int tmp_id = 0;

	


	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		fprintf(stderr, "file not found\n");
		return;
	}
	struct link* tmp = *Head;
	while (tmp->next != NULL)
	{
		fread(tmp_bookname, sizeof(tmp_bookname), 1, fp);
		fread(&tmp_id, sizeof(tmp_id), 1, fp);

		struct link* new_node = (struct link*)malloc(sizeof(struct link));
		if (new_node == NULL) {
			fprintf(stderr, "메모리 할당 실패\n");
			exit(1);
		}
	
		// 노드 생성
		strcpy(new_node->bookname, tmp_bookname);
		new_node->id = tmp_id;
		new_node->next = NULL;
		
		if (Head == NULL) // 첫번째 노드
		{
			*Head = tmp;
			*Tail = tmp;
		}
		else { // 첫번째 노드가 아닌 경우
			(*Tail) -> next = tmp; // 기존 list와 연결 관계 만들기
			*Tail = tmp; // tail이 최종적으로 만들어진 노드를 pointing하게 하기
		}
		tmp = tmp->next;


	}

#ifdef DEBUG
	printf("filename : %s\n", __FILE__);
	printf("function : %s\n", __FUNCTION__);
	printf("line no : %d\n", __LINE__);
#endif	
	fclose(fp);
	return;
}

void save(struct link* Head) {
	FILE* fp;
	struct link* tmp = Head;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		fwrite(tmp->bookname, sizeof((tmp->bookname)),1,fp);
		fwrite(&(tmp->id), sizeof(tmp->id),1, fp);
		tmp = tmp->next;
	}
	fp = fopen("data.txt", "w");
	return;
}