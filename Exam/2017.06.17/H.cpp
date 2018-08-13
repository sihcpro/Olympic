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

int main()
{
	cin >> test;
	
	while( test-- )
	{
		cin >> n;
		
		ll a[n+5];
		fori(n)
		{
			in(a[i]);
		}
		
		set<ll> b;
		stack<ll> c;
		
		b.insert(0);
		fori(n)
		{
			for(set<ll>::iterator j= b.begin(); j != b.end(); j++)
			{
				c.push( *j+a[i] );
			}
			while( !c.empty() )
			{
				b.insert( c.top() );
				c.pop();
			}
		}
		
		cout << b.size() << endl;
	}
}
