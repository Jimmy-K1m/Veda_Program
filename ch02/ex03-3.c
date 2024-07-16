# define _CRT_SECURE_NO_WARNINGS
/*전처리 이전에 define 넣어야함*/
#include <stdio.h>

int main() {

	int n;
	float f;
	char c;
	char str[80];


	printf("정수 실수 문자 입력 : \n");
	scanf("%d", &n);
	scanf("%f", &f); getchar(); // 개행 문자를 문자로 인식할 수 있다.
	scanf("%c", &c);
	scanf("%s", str);


	printf("%d\t%f\t%c\t%s\n", n, f, c, str);

	/*문자와 숫자가 섞여있으면 잘못 된다.*/
	// 초록색 밑줄 warning

	return 0;
}