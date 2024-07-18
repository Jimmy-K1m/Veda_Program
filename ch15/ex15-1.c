#include <stdio.h>


void swap_ptr(char** ppa, char** ppb);

int main()
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb-> %s\n", pa, pb);
	printf("pa -> %p, pb-> %p\n", pa, pb);

	swap_ptr(&pa, &pb); // pa, pb�� �ּ� ���� �ٲ���ϹǷ� call by reference �̿��ؾ���. ���� pa, pb �ּҸ� �����������.
	printf("pa -> %s, pb-> %s\n", pa, pb);
	printf("pa -> %p, pb-> %p\n", pa, pb);

	return 0;

}

void swap_ptr(char** ppa, char** ppb) // �������� �ּҸ� �޾ұ� ������ ���ڸ� ���� �����ͷ� �޾ƾ���.
{

	char* pt;
	pt = *ppa; 
	*ppa = *ppb;
	*ppb = pt;
	// pa�� pb�� �ּҸ� �ٲ�
}