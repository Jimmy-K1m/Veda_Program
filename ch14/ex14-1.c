#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//rand()


/*int main() {

	int num[2][3];
	//char names[5][20];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			num[i][j] = i * j;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/

int main() {

	char names[30][10];
	//char names[5][20];
	//int flag = 0;

	for (int i = 0; i < 30; i++)
	{
		fgets(names[i],10, stdin);
		names[i][strlen(names[i]) - 1] = '\0';

		if (!strcmp(names[i], "end"))
			break;

	}

	for (int i = 0; i < strlen(names); i++)
	{
		if (!strcmp(names[i], "end"))
			break;
		printf("%s\n", names[i]);
	}
	

	return 0;
}