#include <stdio.h>

#define MUL(x, y) ((x)*(y))

 
int main() {
	int x = 5;
	int y = 5;

	printf( "%d\n",MUL(x, y));

	printf("%d\n", MUL(3, 4));
	printf("%d\n", MUL(3, 4-2));

	return 0;
}
