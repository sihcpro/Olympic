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

ll st[120005];
ll a[30005];

void update(long id, long l, long r, long x)
{
	if( x < l || x > r )	return;

	if( l == r )
	{
		st[id]= 0;
		return;
	}

	long mid= ( l+r )/2;
	update( id*2, l, mid, x);
	update( id*2+1, mid+1, r, x);

	st[id]= st[id*2] + st[id*2+1];
}

void build(long id, long l, long r)
{
	if( l == r )
	{
		st[id]= a[l-1];
		return;
	}
	long mid= ( l+r )/2;
	build( id*2, l, mid);
	build( id*2+1, mid+1, r);

	st[id]= st[id*2] + st[id*2+1];
}

ll query(long id, long l, long r, long u, long v)
{
	if( v < l || u > r )
		return 0;

	if( u <= l && v >= r )
		return st[id];

	int mid= (l + r) /2;
	return query(id*2, l, mid, u, v) + query(id*2+1, mid+1, r, u, v);
}

void show()
{
	cout << st[1] << endl;
	d= 2;
	for(ll i= 1; i < n; i++)
	{
	    for(ll j= 0; j < i*2; j++, d++)
            cout << st[d] << "  ";
        cout << endl;
	}
}

int main()
{
	cin >> n;

	fori(n)		in(a[i]);

	build(1, 1, n);

	show();

	fori(n)
	{
	    cout <<  "-----------------" << endl;
		in(sp);
		out(query(1, 1, n, 1, n));
		update(1, 1, n, sp);

		show();
	}

}

