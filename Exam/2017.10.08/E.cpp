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
ll n= 0, k= 0;
string s1, s2;

ll xx1, x2, yy1, y2;

ll ucln( ll xx, ll yy)
{
	while( xx != yy )
	{
		(xx < yy) ? yy-=xx : xx-=yy;
	}
	return xx;
}

int main()
{
	cin >> xx1 >> yy1 >> x2 >> y2;
	
	x= x2-xx1;
	y= y2-yy1;
	ll z;
	
	if( x == 0 || y == 0 )
		z= max( abs(x), abs(y) );
	else
		z= ucln( abs(x), abs(y));	
	
	cout << max( z -1, 0ll );

	return 0;
}








