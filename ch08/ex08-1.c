#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	char arr[100];
	scanf("%s", arr);
	
	for (int i = 0; i < sizeof(arr); i++)
	{
		if ('A' <= arr[i] && 'Z' >= arr[i])
			arr[i] = arr[i]- 'A'+'a';
	}

	printf("%s", arr);

	return 0;
}