#include <stdio.h>

int main()
{
	char ch = 'a';
	int inum = 10;
	float fnum = 1.234;
	void* vp[3];

	//malloc(), memcpy() // �⺻���� void*�̴� � �����̵� ���� �� �ִ�. ���� �Լ��� void�� �Ǵ� ��찡 ����.

	vp[0] = &ch;
	//printf("%c\n", *vp); �ҿ�����
	printf("%c\n", *((char*)vp[0])); // char*�� ����

	vp[1] = &inum;
	printf("%d\n", *((int*)vp[1]));

	vp[2] = &fnum;
	printf("%.3f\n", *((float*)vp[2]));

	return 0;
}