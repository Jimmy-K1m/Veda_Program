#pragma once
void Enter(struct score* stScore, int idx);

void Print(struct score* score, int idx);

//int scoreSearch(int* y, int* score);
void nameDelete(struct score* stScore);
void nameSearch(struct score* stScore);


struct score{

	char name[20];
	int kor;
	int math;
	int eng;
	int science;
};
