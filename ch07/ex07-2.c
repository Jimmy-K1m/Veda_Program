#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "calc.h"
#include <math.h>

int main() {
	int input_ =0;
	scanf("%d", &input_);

	printf("%d", fact(input_));

	return 0;
}