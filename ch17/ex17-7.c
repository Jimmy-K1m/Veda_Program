#include <stdio.h>

union iptype
{
	unsigned char ip[4];
	unsigned int addr;
};//struct��� 5byte �Ҵ�
// ��� ���� �����͸� ���� ����Ѵ�.

int main() {
	union iptype ipaddr;

	ipaddr.addr = 0xc0480a17;
	printf("%d %d %d %d \n", ipaddr.ip[0], ipaddr.ip[1], ipaddr.ip[2], ipaddr.ip[3]); // �޸� �ּҰ� ū ������ 
	//little endian ��� ����
	// ū �� ���� ���� big endian 
	// ���� �� ���� ���� little endian
	// �Ȱ��� ��Ű��ó�� �ƴ� ��쿡 endian ��Ŀ� ���� ����� �� �� �� ����.
	// byte ordering ������ ���� �� ����.


	return 0;
}


