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
#include <map>

using namespace std;

#define mod 10000009ll
#define fori(n) for(ll i= 0; i < n; i++)
#define forj(m) for(ll j= 0; j < n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d", n)
#define outS(s) printf("%s", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0;
ll test;

string s1, s2;

int main()
{
	ll a;
	cin >> n >> a;
	
	double gMax= ( 1.0 - 2.0/(double)n) * (double)180.0;
	double gMin= gMax / (n-2);
	
//	cout << gMin << endl;
//	cout << gMax << endl;
	
	double g= gMin;
	double Min= 180.0;
	ll d= 0, dg= 1;
	while( g <= a+gMin*2 && g <= gMax+gMin )
	{
//		cout << abs( g-(double)a ) << endl;
		if( abs( g-(double)a ) < Min )	
		{
			Min= abs( g-(double)a );
			dg= d+1;
		}
		g+= gMin;
		d++;
	}
	
//	cout << g << endl;
	cout << 1 << " " << n << " " << min( dg+1, n-1);
}
