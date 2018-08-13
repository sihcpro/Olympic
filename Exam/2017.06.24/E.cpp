#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define fori(num) for(ll i= 0; i < num; i++)
#define forj(num) for(ll j= 0; j < num; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0, s;
ll test;

string s1, s2;

ll a[100005];

ll nt[1000000];
ll maxNt= 1;
bool check(ll x)
{
	fori(maxNt)
	{
		if( x % nt[i] == 0 )	return false;
		if( x < nt[i]*nt[i] )	return true;
	}
}

void makeNt()
{
	nt[0]= 2;
	for(ll i=3; i <= 1000100; i+= 2)
	{
		if( check(i) )	nt[maxNt++]= i;
	}
}

int main()
{
	makeNt();

//	fori(100)	out( nt[i] );

	cin >> n;

	d= 1;
	for(ll i= 0; nt[i] <= n; i++)
	{
		s= 0;
		sp= nt[i];
		while( n / sp )
		{
			s+= n/sp;
			sp*= nt[i];
		}
		d= ( d*(s*2+1) ) % 1000007;
//		cout << nt[i] << ": " << s << endl;
	}
	cout << d;
}








