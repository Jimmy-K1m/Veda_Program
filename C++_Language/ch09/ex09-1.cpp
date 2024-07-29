#include "man.h"
#include "woman.h"


int ___main()
{
	Human* pHuman[3] = { new Man("홍길동", 23), new Man("강아지", 27),new Woman("허난설헌", 25) };


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
	
	delete pHuman[0];// new가 같이 생성된 것이 아닌 각각 생성된 것임.
	delete pHuman[1];
	delete pHuman[2];
	return 0;
}
