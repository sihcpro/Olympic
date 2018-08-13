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
#define fori(num) for(ll i= 0; i < num; i++)
#define forj(num) for(ll j= 0; j < num; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0, s;
ll test;

string s1, s2;

ll a[200005];

ll mu(ll soMu, ll so)
{
	if( soMu == 1 )	return so;
	else
	{
		ll num= mu(soMu/2, so);
		num= (num * num) % mod;
		if( soMu % 2 == 0)
			return num;
		else
			return ( num*so ) % mod;
	}
}

ll xuLi(ll i)
{
	ll m= a[i];
	ll kq= 1;
	ll tg= 1;
	forj(m-1)
	{
		tg= (tg*i) % mod;
		kq= (kq*tg) % mod;
	}

//	cout << s << "  s " << endl;
//
//	cout << s-a[i] << "  " << kq << endl;

	ll ans= mu( s/(a[i]) , kq);

//	cout << ans << "  ans " << endl;

	return ans;
}

int main()
{	
	cin >> n;
	
	d= 0;
	fori(n)
	{
		in(sp);
		a[sp]++;
	}
	
	s= 1;
	fori(200005)
	{
		a[i]++;
		s*= a[i];
	}
	
//	cout << s << endl;
	
	ll t= 1;
	for(ll i= 0; i < 200005ll; i++)
	{
		if( a[i] > 1 )		t= ( t*xuLi(i) )%mod;
	}
	
	cout << t;
}

