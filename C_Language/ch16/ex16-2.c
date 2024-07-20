#include <stdio.h>
#include <stdlib.h>  
#include <math.h>

int toInt(char* s);

int main(int argc, char* argv[])
{
	printf("argc : %d\n", argc);
	printf("argv[0] : %s\n", argv[0]);
	printf("argv[1] : %s\n", argv[1]);

	if (argc != 3)
	{
		printf("error\n");
		exit(1);
	}
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	printf("argv[0] + argv[1] : %d\n", a + b);
	printf("argv[0] + argv[1] : %d\n", atoi(argv[1])+ atoi(argv[2]));

	printf("customed value : %d", (toInt(argv[1])+ toInt(argv[2])) );

	return 0;
}

int toInt(char* s)
{
	int len = strlen(s);
	int number = 0;

	for(int i = 0; i < len; i++)
	{
		number += (int)(s[i] - '0') * (pow(10, len - i-1));
	}

	return number;
}
