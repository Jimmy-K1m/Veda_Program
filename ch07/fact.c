int fact(int x)
{
	if (x == 1)
		return 1;
	

	return x * fact(x-1);
}