#include <stdio.h>

enum season { SPRING, SUMMER, FALL, WINTER };

int main() {
	enum season ss;
	char* pc = NULL;

	ss = SPRING;
	
	switch (ss) {
	case SPRING:
	{
		pc = "INLINE"; break;
	}
	case SUMMER:
	{
		pc = "SKATING"; break;
	}
	case FALL:
	{
		pc = "TRIP"; break;
	}
	case WINTER:
	{
		pc = "SNOWBOARDING"; break;
	}
	}

	printf("���� ���� Ȱ�� -> %s", pc);

	return 0;
}


