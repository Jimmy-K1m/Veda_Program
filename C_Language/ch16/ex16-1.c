#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)malloc( 10 * sizeof(int));
	if (p == NULL)
	{
		printf("Memory ����\n");
		return 0; //exit(1)
	}
	//*(p+0) = 100;
	for(int i = 0; i <10; i++)
		p[i] = 100 + i;
	for (int i = 0; i < 10; i++)
		printf("&p[%d] : %p,\t p[%d] : %d\n", i,&p[i],i, p[i]);

	p = realloc(p, 20 * sizeof(int)); // �߰� �Ҵ�
	for (int i = 10; i < 20; i++) // ������ 10���� �̹� ä��������.
		p[i] = 100 + i;

	for (int i = 0; i < 20; i++)
		printf("&p[%d] : %p,\t p[%d] : %d\n", i, &p[i], i, p[i]); // 20���� ũ�� �þ.

	free(p);

	return 0;
}