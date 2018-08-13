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


queue<long> c;
ll t, m, sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0, s;
ll test;

string s1, s2;

long a[100005];
long b[1005];

int main()
{
	cin >> x >> y;
	cin >> n;

	long db= 0;
	fori(n)
	{
		bool kt= true;
		in(sp);
		forj(db)
			if( sp == b[j] && sp == 1 )
			{
				kt= false;
				break;
			}
		if( kt )	b[db++]= sp;
	}

	if( y == x )
	{
		cout << 0;
		return 0;
	}

	c.push(x);
	a[x]= 0;
	d= 0;
	while( !c.empty() )
	{
		sp= c.front();
		top= c.size();
		c.pop();
		fori(db)
		{
			m= ( sp * b[i] )%100000;
			if( m == y )
			{
				cout << a[sp]+1;
				return 0;
			}
			if( a[m] == 0 )
			{
				a[m]= a[sp]+1;
				c.push(m);
			}
		}
	}

	cout << -1;
}

