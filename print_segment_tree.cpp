void printSegmentTree(int n)
{
	int i= 0;
	while( (1<<(i-1)) < n*2 )
	{
		ll now= 1<<(i-1);
		for0(j, now )
		{
			cout << now+j << " ";
		}
		cout << endl;
		i++;
	}
}
