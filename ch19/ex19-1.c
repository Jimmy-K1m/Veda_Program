#include <stdio.h>
#define MAX 5

int main() {
	int num[MAX];

	for (int i = 0; i < MAX; i++)
		num[i] = i;

	for (int i = 0; i < MAX; i++)
		printf("%d\n", num[i]);


	return 0;
}
