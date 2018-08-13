#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define for0(i, num) for(ll i= 0; i < num; i++)
#define for1(i, num) for(ll i= 1; i <= num; i++)
#define fordown(num) for(ll i= num-1; i >= 0; i--)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll t, m, sp, junger, mid, top, bot, d, test;
ll n= 0, k= 0;
string s1, s2;

long a[1000005];
bool b[1000005];

pair<ll, ll> binariSearch(ll x, ll bot, ll top)
{
    ll mid= (top + bot)/2;
	if( bot == top )
	{
		if( a[mid] < x )
			return pair<ll, ll>( mid, mid+1);
		else
			return pair<ll, ll>( mid-1, mid);
	}
	else if( x < a[mid] )	return binariSearch(x, bot, mid);
	else					return binariSearch(x, mid+1, top);
}

ll mark(long l, long r, long x, long y)
{
	if( x > y )	return 0;
	
	long mid= (l+r)/2;
	
	pair<ll, ll> midle= binariSearch( mid, x, y);
//	cout << midle.first << "|" << midle.second << endl;
	mid = ( a[midle.first] - l < r - a[midle.second] ) ? midle.second : midle.first;
	
	b[mid] = true;
	
	cout << a[mid] << "  "  << r-l << endl ;
	
	d+= max( r-l , 0l);
	return mark( l, a[mid]-1, x, mid-1 ) + mark( a[mid]+1, r, mid+1, y );
}

int main()
{
	cin >> n >> m;
	
	for1(i, m)
		scanf("%ld", &a[i]);
		
	a[0]= 1;
	a[m+1]= n;

	sort( a, a+m+2);

	d= 0;
	mark(1, n, 1, m);	
	cout << d;
	
	return 0;
}








