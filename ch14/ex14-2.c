#include <stdio.h>

/*
int main()
{
	char* ptr[3];
	//char ptr[3][7];
	
	char ptr_[2];

	char ptr1[2];

	ptr[0] = ptr_;
	ptr[1] = ptr1;
	ptr[2];

	for (int i = 0; i < 2; i++)
	{
		printf("%p\n", ptr[i]);//포인터 기호를 안 써도 된다.
	}

	//printf("address is %p\n", ptr[0]);
	//printf("address is %p\n", ptr[1]);
	//printf("address is %p\n", ptr[2]);

	return 0;
}
*/

int main()
{
	char* ptr[3];
	//char ptr[3][7];
	
	ptr[0] = "hello";
	ptr[1] = "hi";
	ptr[2] = "bye";


	for (int i = 0; i < 3; i++)
	{
		printf("%p\n", ptr[i]);//포인터 기호를 안 써도 된다.
	}

	//printf("address is %p\n", ptr[0]);
	//printf("address is %p\n", ptr[1]);
	//printf("address is %p\n", ptr[2]);

	return 0;
}