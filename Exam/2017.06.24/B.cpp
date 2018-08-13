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

ll a[100005];

int main()
{
	ll x1, y1, x2, y2, x3, y3;
	
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	
	ll Max= 3;
	
	if( x1 == x2 &&  ( y1 == y3 || y2 == y3 ) )	Max= 2;
	if( x1 == x3 &&  ( y1 == y2 || y3 == y2 ) )	Max= 2;
	if( x2 == x3 &&  ( y2 == y1 || y3 == y1 ) )	Max= 2;

	if( ( x1 == x2 && x1 == x3 ) || ( y1 == y2 && y2 == y3 ) )	Max= 1;
		
	cout << Max;
}








