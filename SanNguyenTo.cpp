long ntLeng = 10000050;
bool *ntBool = new bool[ntLeng+1];
bool makeNtBool()
{
	ntBool[0]= ntBool[1]= false;
	rep(2,i,ntLeng)
		ntBool[i]= true;
	for(long i= 4l; i < ntLeng; i+= 2)
		ntBool[i]= false;
	long i= 1l;
	while( i < ntLeng ) {
		i+= 2;
		if( !ntBool[i] )
			continue;
		for(long j= i*i; j < ntLeng; j+= i)
			ntBool[j]= false;
	}
}

long nt[1000050];
long lengNt= 0;
void makeNt()
{
	makeNtBool();
	nt[lengNt++]= 2;
	for(ll i= 3; i < ntLeng; i+= 2)
		if( ntBool[i] )
			nt[lengNt++]= i;
}