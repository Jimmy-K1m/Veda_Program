# define _CRT_SECURE_NO_WARNINGS
/*��ó�� ������ define �־����*/
#include <stdio.h>

int main() {

	int n;
	float f;
	char c;
	char str[80];


	printf("���� �Ǽ� ���� �Է� : \n");
	scanf("%d", &n);
	scanf("%f", &f); getchar(); // ���� ���ڸ� ���ڷ� �ν��� �� �ִ�.
	scanf("%c", &c);
	scanf("%s", str);


	printf("%d\t%f\t%c\t%s\n", n, f, c, str);

	/*���ڿ� ���ڰ� ���������� �߸� �ȴ�.*/
	// �ʷϻ� ���� warning

	return 0;
}