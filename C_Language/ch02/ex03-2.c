#include <stdio.h>

int main(void)
{
	char fruit[20] = "strawberry";
	char fruit_[6] = "apple";


	printf("%s\n", fruit); // �迭�� = �迭�� ���� �ּ�
	char ch = 'A';
	printf("%d\n", ch);
	printf("%x\n", fruit+1);

	return 0;
}

// strcmp�� fruit == "apple"�� ��ü�ؾ���.