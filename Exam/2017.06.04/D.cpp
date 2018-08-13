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

ll a[36];

ll f(ll N)
{
	if ( a[N] != 0 )return a[N];
	return a[N]= f(N - 1) + f(N - 2) + f(N - 3);
}

void makeArray()
{
	a[0]= 1;
	a[1]= 1;
	a[2]= 1;
	for(ll i= 3; i < 36; i++)
	{
		f(i);
//		cout << a[i] << endl;
	}
}

char find(ll n, ll k)
{
	if( n == 0 )				return 'a';
	if( n == 1 )				return 'b';
	if( n == 2 )				return 'c';
	if( k <= a[n-1] )			return find(n-1, k);
	if( k <= a[n-1] + a[n-2] )	return find(n-2, k - a[n-1] );
								return find(n-3, k - a[n-1] - a[n-2]);
}

int main()
{	
	makeArray();

	cin >> n >> k;
	
//	for(k= 1; k <= a[n]; k++)
	{
		if( k > a[n] )	cout << "-1";
		else			cout << find(n, k);
	}
	
}

