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

ll n, m, sp, mid, top, bot;
string s1, s2;

long a[1005][1005];

int check(long x, long y, long z, long t)
{
	long p= x;
	if( x == y || x == z || x == t )
		p= x;
	else if( y == z || y == t )
		p= y;
	else
		p= z;
	
	return  ( 4- ( ( p == x ) + ( p == y ) + ( p == z ) + ( p == t ) ) );
}

int main()
{
	cin >> n >> m;
	
	for0(i, n)
		for0(j, m)
			scanf("%ld", &a[i][j]);
	
	long x, y, z, t, d= 0;
	for0(i, (n)/2)
		for0(j, (m)/2)
		{
			x= a[i][j];
			y= a[n-i-1][j];
			z= a[i][m-j-1];
			t= a[n-i-1][m-j-1];
			
//			printf("%ld %ld %ld %ld \n", x, y, z, t);
			
			d+= check( x, y, z, t);			
		}
//	cout << d << endl;
	
	if( n%2 )
		for0(i, m/2){
			d+= ( a[n/2][i] != a[n/2][m-i-1] );
		}
//	cout << d << endl;

	if( m%2 )
		for0(i, n/2){
			d+= ( a[i][m/2] != a[n-i-1][m/2] );
		}
	cout << d << endl;
	
	return 0;
}








