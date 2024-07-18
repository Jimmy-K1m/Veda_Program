#include <stdio.h>

int main() {
	struct bit {
		unsigned char b1 : 4; // 0000 : 100m/s , 0001 : 200m/s 왼쪽과 같이 임의 지정 가능
		unsigned char b2 : 2; // 00 : on, 11 : off
		// byte를 bit 단위로 나눔
		// 메모리 공간 save 가능
	} ch;

	printf("size : %d\n", sizeof(ch));

	ch.b1 = 0x0f;
	ch.b2 = 0x01;

	printf("ch.b1 : %u, ch.b2 : %u\n", ch.b1, ch.b2);

}