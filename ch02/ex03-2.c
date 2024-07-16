#include <stdio.h>

int main(void)
{
	char fruit[20] = "strawberry";
	char fruit_[6] = "apple";


	printf("%s\n", fruit); // 배열명 = 배열의 시작 주소
	char ch = 'A';
	printf("%d\n", ch);
	printf("%x\n", fruit+1);

	return 0;
}

// strcmp로 fruit == "apple"을 대체해야함.