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


ll t,  sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0, s;
ll test;

string s1, s2;

ll a[1000005];

struct mm{
	ll mi, ma;

	mm(ll i= 1000000000, ll a= -1000000000)
	{
		mi= i;
		ma= a;
	}
};

mm m[1000005*4];

mm operator + (const mm& left, const mm& right)
{
	return mm( min(left.mi, right.mi), max( left.ma, right.ma));
}

void make(ll id, ll l, ll r)
{
	if( l == r )
	{
		m[id]= mm(a[l-1], a[l-1]);
//		cout << a[l-1] << endl;
		return;
	}

	ll mid=(r+l)/2;
	make(id*2, l, mid);
	make(id*2+1, mid+1, r);

	m[id]= m[id*2]+m[id*2+1];
}

mm query(long id, long l, long r, long u, long v)
{
	if( v < l || u > r )
		return mm();

	if( u <= l && v >= r )
		return m[id];

	int mid= (l + r) /2;
	return query(id*2, l, mid, u, v) + query(id*2+1, mid+1, r, u, v);
}

int main()
{
	cin >> n;

	fori(n)
	{
		in(a[i]);
	}
	make(1, 1, n);

//	cout << m[1].ma << "  " << m[1].mi << endl;

//	cout << m[1].ma << "|" << m[1].mi << endl;
//	for(ll i= 1; i < 4; i++)
//    {
//        x= pow(2, i);
//        for(ll j= 0; j < x; j++)
//        {
//            cout << m[x+j].ma << "|" << m[x+j].mi << "  ";
//        }
//        cout << endl;
//    }


//	if( n < 3 )
//		cout << 0;
//	else if ( n == 3 )
//		cout << max( abs( a[0]-a[1] ), abs( a[1] - a[2]) );
//	else
	{
		ll Max= 0;
	    for(ll i= 1; i <= n-1; i++)
	    {
	        mm m1= query(1, 1, n, 1, i);
	        mm m2= query(1, 1, n, i+1, n);
	        sp= m1.ma - m1.mi + m2.ma - m2.mi;
	        if( sp > Max )  Max= sp;
	    }
	    cout << Max;
	}
}








