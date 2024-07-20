#include <stdio.h>
#include "linked.h"

/*
int main() {

	struct simple {
		int id;
		double dnum;
		struct simple* next;
	};

	struct simple s1 = { 100, 123.45, NULL }, s2 = {200, 37.8, NULL }, * ptr;
	struct simple s3[2] = { {100,123.45}, {200,123.65} };

	printf("s1 : %d, %.2lf\n", s1.id, s1.dnum);
	printf("s2 : %d, %.2lf\n", s2.id, s2.dnum);



	ptr = &s1;
	ptr->next = &s2;

	printf("*ptr : %d, %.2lf\n", ptr->id, ptr->dnum);
	printf("\n****************\n*ptr->next : %d, %.2lf\n", ptr->next->id, ptr->next->dnum);

	ptr = &s2;

	printf("*ptr : %d, %.2lf\n", ptr->id, ptr->dnum);

	for(int i = 0; i < 2; i++)
	printf("s[%d] : %d, %.2lf\n", i, s3[i].id, s3[i].dnum);

	return 0;
}

*/
// 구조체 하나 만들기

int main() {

	int i;
	printf("input number 1~3 \n");
	scanf("%d", &i);
	struct link* book_ptr = NULL;
	struct link* head;
	struct link* tail;
	//struct link* new_b = (struct link*)malloc(sizeof(struct link));
	switch (i)
	{
	case(1):
		
		Enter(book_ptr);

	
	case(2):

	
	case(3):

	}

}