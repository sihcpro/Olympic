
long long b[10000];

bool nim(long long db)
{
	long long x= 0;
	for(long long i= 0; i < db; i++)
        x^= b[i];

	for(long long i= 0; i < db; i++)
	{
		if( (b[i]^x) < b[i] )
		{
			return true;
		}
	}
	return false;
}


