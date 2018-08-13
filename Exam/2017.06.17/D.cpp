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

ll a[30][100005];
ll b[30];

ll* Search= new ll[100005];
ll binariSearch(ll x, ll bot, ll top)
{
    ll mid= (top + bot)/2;
	if( x == Search[mid] )		return mid;
	else if( bot == top )		return mid;
	else if( x < Search[mid] )	return binariSearch(x, bot, mid);
	else						return binariSearch(x, mid+1, top);
}

int main()
{
	cin >> s1;
	cin >> s2;
	
	fori(s1.length())
	{
		sp= s1[i]-'a';
		a[ sp ][ b[sp]++ ]= i;
	}
	
	ll now= -1;
	bool kt;
	ll d= 1;
	fori(s2.length())
	{
		sp= s2[i]-'a';
		
		if( b[sp] == 0 )
		{
			cout << -1;
			return 0;
		}
		else
		{
			if( a[sp][ b[sp]-1 ] > now )
			{
				Search= &(a[sp][0]);
				ll j= binariSearch( now, 0, b[sp]-1 );				
				for(; j < b[sp]; j++ )
				{
					if( a[sp][j] > now )
					{
						now= a[sp][j];
						break;
					}
				}
			}
			else
			{
				d++;
				now= a[sp][0];
			}
		}
	}
	
	cout << d;
}
