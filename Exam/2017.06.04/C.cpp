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
ll n= 0, k= 0, s;
ll test;

string s1, s2;

ll a[1005];
ll b[1005];

int main()
{	
	cin >> n;

	fori(n)
	{
		in(a[i]);
	}
	
	fori(n)
	{
		for(ll j= i+1; j < n; j++)
			if( a[j] > a[i] )
				if( b[j] < b[i] + 1 )	
					b[j]= b[i] + 1;
	}
	m= b[0];
	fori(n)
	{
		if( b[i] > m )	m= b[i];
	}
	
	cout << m+1;
}

