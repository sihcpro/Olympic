#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define fori(num) for(ll i= 0; i < num; i++)
#define forj(num) for(ll j= 0; j < num; j++)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d, test;
ll n= 0, k= 0, s;

ll ucln(ll a,ll b)
{
	while( a != b )
	{
		(a>b)?a-=b:b-=a;
	}
	return a;
}

int main()
{
	cin >> x >> y;
	
	y = max(x, y);
	
	ll z = (7-y);
	
	ll u = ucln(z, 6);
	
	cout << (z/u) << "/" << (6/u) << endl;

	return 0;
}








