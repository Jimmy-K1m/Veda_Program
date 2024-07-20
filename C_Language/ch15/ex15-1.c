#include <stdio.h>


void swap_ptr(char** ppa, char** ppb);

int main()
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb-> %s\n", pa, pb);
	printf("pa -> %p, pb-> %p\n", pa, pb);

	swap_ptr(&pa, &pb); // pa, pb의 주소 값을 바꿔야하므로 call by reference 이용해야함. 따라서 pa, pb 주소를 전달해줘야함.
	printf("pa -> %s, pb-> %s\n", pa, pb);
	printf("pa -> %p, pb-> %p\n", pa, pb);

	return 0;

}

void swap_ptr(char** ppa, char** ppb) // 포인터의 주소를 받았기 때문에 인자를 이중 포인터로 받아야함.
{

	char* pt;
	pt = *ppa; 
	*ppa = *ppb;
	*ppb = pt;
	// pa와 pb의 주소를 바꿈
}