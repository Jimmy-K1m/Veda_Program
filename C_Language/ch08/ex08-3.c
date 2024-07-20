#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int main()
{
	char name[10] = "";

	fgets(name, 10, stdin);
	name[strlen(name) - 1] = '\0';
	printf("%s\n", name);


	//if ( !strcmp(name, "kim") ) {
		if(sizeof(name) - strlen(name) > strlen(" kildong"))
			strcat(name, " kildong");
		printf(name);
	//}

	int n = strcmp(name, "kim");
	printf(" %d\n", n);


	return 0;
}