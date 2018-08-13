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

ll m, sp, junger, mid, top, bot, d, test;
ll n= 0, k= 0;
string s1, s2;

struct wall{
	long h, l, s, t;
	wall(){
		h= l= s= t= 0;
	}
};

wall a[100005];
ll b[100005];
ll t[100005];

bool greate(wall w1, wall w2)
{
	return (w1.l < w2.l);
}

ll binariSearch(ll x, ll bot, ll top)
{
    ll mid= (top + bot)/2;
//	if( x == Search[mid] )		return mid;
	if( bot == top )			return mid;
	else if( x <= b[mid] )		return binariSearch(x, bot, mid);
	else						return binariSearch(x, mid+1, top);
}

int main()
{
	cin >> test;

	while( test-- )
	{
		cin >> n;

		for1(i, n)
			scanf("%ld", &a[i].l);
		for1(i, n)
			scanf("%ld", &a[i].h);

		sort(a+1, a+n+1, greate);
//
//		for1(i, n)
//			cout << a[i].h << " ";
//		cout << endl;

		t[1]= a[1].h;
		for(long i= 2; i <= n; i++)
			t[i]= t[i-1]+a[i].h;

		a[0].h = 1000000005l;
		a[0].l = -1;
		a[0].s = 0;

		stack<long> c;
		c.push(0);
		for1(i, n)
		{
			ll s= 0;
			while( !c.empty() && a[c.top()].h < a[i].h )
			{
				s+= a[c.top()].s + a[c.top()].h;
				c.pop();
			}
			a[i].s= s;
			long last = c.top();
			c.push(i);
			b[i]= a[i].h*( a[i].l - a[last].l -1 ) + b[last] - a[i].s;
//			cout << i << "  " << b[i] << endl;
		}

		cin >> m;

		ll s= 0;
		ll j= 1;
		for0(i, m)
		{
			scanf("%lld", &sp);
//			s+= sp;
			j= binariSearch(sp, 1, n);
			if( b[j] >= sp )
				cout << j-1 << endl;
			else
				cout << j << endl;
		}

	}

	return 0;
}








