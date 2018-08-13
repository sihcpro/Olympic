ll* nt= new ll[1000000];
bool checkNt(ll x)
{
	ll kt= sqrt(x);
    for(ll i= 0; nt[i] <= kt; i++)
        if( x % nt[i] == 0 )	return false;
	return true;
}

ll maxNt= 1;
void makeNt()
{
    nt[0]= 2;
    for(ll i= 3; i < 1000005; i+= 2)
        if( checkNt(i) )    nt[maxNt++]= i;
}
