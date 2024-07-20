#include <stdio.h>

int main()
{
	char ch;
	char* cp;
	int inum, * ip;
	double dnum, * dp;

	cp = &ch;
	ip = &inum;
	dp = &dnum;

	printf("cp : %p, ip : %p, dp : %p\n", cp, ip, dp);
	printf("&ch : %p, &inum : %p, &dnum : %p\n", &ch, &inum, &dnum);

	ch = 'B';
	inum = 1000;
	dnum = 1.23455;


	printf("*cp : %c, *ip : %d, *dp : %lf\n", *cp, *ip, *dp);


	cp++, dp++, ip++;
	printf("cp : %p, ip : %p, dp : %p\n", cp, ip, dp);

	return 0;
}