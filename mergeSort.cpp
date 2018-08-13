vector<long> mergeSort( const vector<long> &a ){
	if( a.size() == 1 )
		return a;

	vector<long> a2, a3, c;
	for0(i, a.size())
		( i < a.size()/2 ) ? a2.push_back(a[i]) : a3.push_back(a[i]);
	a2= mergeSort( a2 );
	a3= mergeSort( a3 );
	int i= 0, j= 0;
	while( i+j < a.size() ){
		if( j >= a3.size() || ( i < a2.size() && a2[i] < a3[j] ) )
			c.push_back( a2[i++] );
		else
			c.push_back( a3[j++] );
	}
	return c;
}

