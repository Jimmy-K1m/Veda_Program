#include <stdio.h>

void func();

int gv = 20;

int main(int argc, char* argv[]) {
	
	int lv = 10;

	printf("%p, %p\n", &gv, &lv); // �������� �ּ�, �������� �ּ�  �ּ� ���� gap�� ū �ɷ� ����.
	printf("%p\n", &argc); // �Ű����� �ּ�(�������� ���� ���ԵȰɷ� ����)

	for(int i = 0; i < 10; i++)
		func();

	return 0;
}

// �Լ��� ������ ������������ �޸� �Ҵ� ������.

void func() {
	static int num = 100;


	printf("%d\n", num++);
	printf("%p\n", &num);
}