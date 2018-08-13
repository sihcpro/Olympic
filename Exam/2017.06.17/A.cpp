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
	cin >> n >> k;

	cin >> s1;

	ll max1= 0, max2= 0;

	bot= 0;
	top= 0;
	s= 0;
	char check= '0';
	while( top < n || s > k )
	{
		if( s <= k )
		{
			if( s1[top++] != check )	s++;
		}
		else
		{
			if( s1[bot++] != check )	s--;
            if( top - bot > max1 )	max1= top - bot;
		}
	}
    if( top - bot > max1 )	max1= top - bot;

	bot= 0;
	top= 0;
	s= 0;
	check= '1';
	while( top < n || s > k )
	{
		if( s <= k )
		{
			if( s1[top++] != check )	s++;
		}
		else
		{
			if( s1[bot++] != check )	s--;
            if( top - bot > max2 )	max2= top - bot;
		}
	}
    if( top - bot > max2 )	max2= top - bot;

	cout << max( max1, max2);
}



