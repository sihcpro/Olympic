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


ll t, m, sp, junger, mid, top, bot, x, y, d, test;
ll n= 0, k= 0, s;
string s1, s2;

bool nt[10000050] = {false};
void makeNt()
{
	nt[0]= 1, nt[1]= 1;
	for(ll i= 2; i < 10000005; i++)
	{
		if (nt[i] == 0) {
		    for (ll j = (ll) i * i; j <= 10000000; j += i) nt[j] = 1;
		}
	}
}

ll c[1000000];

int main()
{
	makeNt();

	ll lengNt= 0;
	for( ll i= 2; i < 10000005; i++ )
		if( !nt[i] )
			c[lengNt++]= i;
//	for0( i, 50)
//		cout << c[i] << endl;

	ll a, b;
	cin >> a >> b >> k;

	ll nta= -1, ntb= -1;
	for0( i, lengNt)
	{
		if( c[i] >= a )
		{
			if( nta == -1 )
				nta= i;
			if( c[i] <= b )
				ntb= i;
		}
	}
	
//	cout << nta << "  " << ntb << endl;
//	for(ll i= nta; i <= ntb; i++)
//		cout << c[i] << " ";
//	cout << endl;
	
	if( nta == -1 || ntb == -1 || ntb - nta +1 < k )
	{
		cout << -1;
		return 0;
	}

	m= max( b-c[ntb-k+1]+1, c[nta+k-1]-a+1 );

//	cout << ntb-k+1 << "  " << nta+k-1 << endl;
//	cout << c[ntb-k+1] << "  " << c[nta+k-1] << endl;
//	cout << m << endl;

	if( ntb - nta +1 == k )
	{
		cout << m;
		return 0;
	}
	
	for(int i= nta; i < ntb-k+1 ; i++)
	{
//		cout << c[i+k] << " : " << c[i] << endl;
		m= max( m, c[i+k]-c[i]);
	}
	cout << m << endl;

//	x= a, y= a;
//	d= !nt[x];
//	m= 10000050;
//	while( y <= b )
//	{
//		if( d <= k+1 )
//		{
//			if( d == k && m > b-a+1 )
//				m= b-a+1;
//			d+= !nt[++y];
//		}
//		else
//		{
//			d-= !nt[--x];
//			if( m < y-x-1 )
//				m= y-x-1;
//		}
//	}

	return 0;
}








