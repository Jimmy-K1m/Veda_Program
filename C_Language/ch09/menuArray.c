void scoreEnter(int* score)
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);
	}
	
}

void scorePrint(int* score)
{

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", score[i]);
	}
	
}

int scoreSearch(int*y,  int* score)
{
	int x;

	scanf("%d", y);
	
	return score[*y];
}