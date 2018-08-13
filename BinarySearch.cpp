ll* Search= newNt;
ll binariSearch(ll x, ll bot, ll top)
{
    ll mid= (top + bot)/2;
	if( x == Search[mid] )		return mid;
	else if( bot == top )		return -1;
	else if( x < Search[mid] )	return binariSearch(x, bot, mid);
	else						return binariSearch(x, mid+1, top);
}