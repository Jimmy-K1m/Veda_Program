#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "structure.h"



int main() {

	struct member person[5];

	for (int i = 0; i < 5; i++) {
		printf("나이: ");
		scanf("%d", &person[i].age); getchar();
		printf("이름: ");
		fgets(person[i].name, 20, stdin);
		person[i].name[strlen(person[i].name) - 1] = '\0';
	}

	// person 삭제
	struct member temp;

	temp = person[2] ;
	person[2] = person[3];
	person[3] = temp;

	person[4].age = 0;
	strcpy(person[4].name, "");

	for (int i = 0; i < 5; i++)
		printf("person");

	return 0;
}