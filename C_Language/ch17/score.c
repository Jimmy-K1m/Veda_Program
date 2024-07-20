#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct score {

	char name[20];
	int kor;
	int math;
	int eng;
	int science;
};


void Enter(struct score* stscore, int i)
{
	//scanf("%s", stscore[i].name);
	fgets( stscore[i].name , 20, stdin);
	stscore[i].name[strlen(stscore[i].name) - 1] = '\0';
	//printf("%d\n", i);
	scanf("%d", &stscore[i].kor); 
	scanf("%d", &stscore[i].eng);
	scanf("%d", &stscore[i].math);
	scanf("%d", &stscore[i].science); getchar();

}

void Print(struct score* stscore, int idx)
{
	for (int i = 0; i < idx; i++) {
		printf("%s\n", stscore[i].name);
		printf("%d\n", stscore[i].kor);
		printf("%d\n", stscore[i].eng);
		printf("%d\n", stscore[i].math);
		printf("%d\n", stscore[i].science);
	}
}



void nameSearch(struct score* stScore)
{
	char* tempName[20];

	fgets(tempName, 20, stdin);


	for(int i = 0; i < 30;i++)
	if (strcmp(tempName, stScore[i])){
		printf("Name is %s", stScore[i].name);
		printf("korean score is %d", stScore[i].kor);
		printf("english score is %d", stScore[i].eng);
		printf("math score is %d", stScore[i].math);
		printf("science score is %d", stScore[i].science);
	}

}

void nameDelete(struct score* stScore)
{
	char* tempName[20];

	fgets(tempName, 20, stdin);


	for (int i = 0; i < 30; i++) {
		if (!strcmp(tempName, stScore[i].name)){
			strcpy(stScore[i].name,"");
			stScore[i].kor = 0;
			stScore[i].math = 0;
			stScore[i].eng = 0;
			stScore[i].science = 0;
		}
	}
}

