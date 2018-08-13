#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <fstream>
#include <string.h>
#include <set>

using namespace std;

#define mod 1000000007ll
#define fori(n) for(ll i= 0; i < n; i++)
#define forj(n) for(ll j= 0; j < n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0, s, d= 0;
ll test;

string s1, s2;

ll a[3005];
ll b[3005];

int main()
{	
	cin >> n >> k;
	
	fori(n)
	{
		in(d);
		in(s);
		b[d]+= s;
	}
	
	fori(3002)
	{
		s= b[i];
		d= i;
		if( a[d] < k )
		{
			if( a[d]+s > k )
			{
				s= a[d]+s - k;
				a[d]= k;
			}
			else
			{
				a[d]+= s;
				s= 0;
			}
//			cout << d << " -> " << a[d] << endl;
		}
		if( a[d+1] < k )
		{
			if( a[d+1]+s > k )
			{
				s= a[d+1]+s - k;
				a[d+1]= k;
			}
			else
			{
				a[d+1]+= s;
				s= 0;
			}
//			cout << d+1 << " -> " << a[d+1] << endl;
		}
	}
	s= 0;
	fori(3002)
	{
		if( a[i] != 0 )
		{
			s+= a[i];
//			cout << i << "  " << a[i] << " -> " << s << endl;
		}
	}
	
	cout << s;
}

