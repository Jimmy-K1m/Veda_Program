#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
/*
int main()
{
	int score[30];

	int cnt = 0;
	int total = 0;
	
	while (cnt < 30)
	{
		scanf("%d", &score[cnt]);
		if (score[cnt] == -1)
			break;
		total += score[cnt];
		cnt++;

	}

	printf("The average score is %.2f \n",(float)total / cnt);
	printf("%d\n", score[5]);
	printf("size of score_array is %d \n", sizeof(score)/sizeof(int));
	return 0;
}
*/

int main() {
	int rank[30];
	int score[30];
	int cnt = 0;
	int total = 0;

	while (cnt < 30)
	{
		scanf("%d", &score[cnt]);
		if (score[cnt] == -1)
			break;
		total += score[cnt];
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
	{
		int tmp = 0;
		for (int j = 0; j<cnt; j++)
		{
			if (i == j)
				continue;
			if (score[i] < score[j])
				tmp++;
		}
		rank[i] = tmp+1;
	}
	printf("\n*********rank*********\n");
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", rank[i]);
	}

}