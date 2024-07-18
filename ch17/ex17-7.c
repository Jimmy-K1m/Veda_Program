#include <stdio.h>

union iptype
{
	unsigned char ip[4];
	unsigned int addr;
};//struct라면 5byte 할당
// 멤버 간에 데이터를 같이 사용한다.

int main() {
	union iptype ipaddr;

	ipaddr.addr = 0xc0480a17;
	printf("%d %d %d %d \n", ipaddr.ip[0], ipaddr.ip[1], ipaddr.ip[2], ipaddr.ip[3]); // 메모리 주소가 큰 공간에 
	//little endian 방식 차용
	// 큰 쪽 먼저 저장 big endian 
	// 작은 쪽 먼저 저장 little endian
	// 똑같은 아키텍처가 아닌 경우에 endian 방식에 따라 통신이 안 될 수 있음.
	// byte ordering 문제가 생길 수 있음.


	return 0;
}


