#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <fstream>
#include <string.h>
#include <set>

using namespace std;

#define mod 1000000007ll
#define fori(n) for(ll i= 0; i < n; i++)
#define forj(n) for(ll j= 0; j < n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0, s, d= 0;
ll test;

string s1, s2;

ll tinh(ll s)
{
	ll kq= 0;
	while( s > 0 )
	{
		kq+= s;
		s/= k;
	}
	return kq;
}

int main()
{	
	cin >> n >> k;
	
	if( k == 1 )
	{
		cout << 1;
		return 0;
	}
	double s= (double)n * (double)((double)1.0- 1.0/(double)k);
	
	m= (ll)s;
	
	while( tinh(m) < n )
	{
		m++;
	}
	
	cout << m;
}

