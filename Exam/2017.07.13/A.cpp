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
	cout << 1000000000 % 3 << endl;
	cin >> n;
	long a[n+5];
	stack<long> b;
	map<long, bool> c;
	fori(n)		
		cin >> a[i];
	sort( a, a+n);
	fori(n)
	{
//		cout << a[i] << endl;
		c[ a[i] ]= true;
		b.push( a[i] );
	}
	
	sp= b.top();
	b.pop();
	long kq= 0;
	while( !b.empty() )
	{
		cout << b.top() << "  " << sp << endl;
		long sp2= abs( sp - b.top() );
		long sp3= abs( b.top() % sp );
		if( c.find(1) != c.end() )
		{
			kq= a[n-1];
			break;
		}
		if( c.find( sp3 ) == c.end() )
		{
			b.push( sp3 );
			c[sp3]= true;
		}
		if( c.find( sp2 ) == c.end() )
		{
			b.push( sp2 );
			c[sp2]= true;
		}
		else
		{
			sp= b.top();
			b.pop();
		}
	}
	if( kq == 0 )	kq= c.size();
	
//	cout << kq;
	if( ( kq-n ) %2 == 0 )
		cout << "Ba";
	else
		cout << "An";
	
	return 0;
}








