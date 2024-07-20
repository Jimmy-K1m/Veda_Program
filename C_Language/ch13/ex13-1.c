#include <stdio.h>

void func();

int gv = 20;

int main(int argc, char* argv[]) {
	
	int lv = 10;

	printf("%p, %p\n", &gv, &lv); // 전역변수 주소, 지역변수 주소  주소 간의 gap이 큰 걸로 보임.
	printf("%p\n", &argc); // 매개변수 주소(지역변수 군에 포함된걸로 보임)

	for(int i = 0; i < 10; i++)
		func();

	return 0;
}

// 함수가 끝나면 지역변수들이 메모리 할당 해제됨.

void func() {
	static int num = 100;


	printf("%d\n", num++);
	printf("%p\n", &num);
}