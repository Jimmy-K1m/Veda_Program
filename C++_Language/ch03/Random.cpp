#include <stdlib.h>
#include "Random.h"

int Random::nextInRange(int x, int y) {
	if (x > y)
		return rand() % (x - y + 1) + y; // x- y + 1 �� ���� ����  +y�� �����̵�
	else
		return rand() % (y - x + 1) + x;
};

int Random::next() { return rand() % RAND_MAX; };

Random::Random() {};