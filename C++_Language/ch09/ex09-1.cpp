#include "man.h"
#include "woman.h"


int ___main()
{
	Human* pHuman[3] = { new Man("ȫ�浿", 23), new Man("������", 27),new Woman("�㳭����", 25) };


	for (int i = 0; i < 3; i++)
	{
		pHuman[i]->show();
		/*
		if (i == 2)
			((Woman*)pHuman[i])->show();
		else
			((Man*)pHuman[i])->show();
		*/
	}
	
	delete pHuman[0];// new�� ���� ������ ���� �ƴ� ���� ������ ����.
	delete pHuman[1];
	delete pHuman[2];
	return 0;
}
