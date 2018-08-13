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

pqmax a[1005];
ll b[1005];

int main()
{	
	cin >> n >> m >> k;
	
	fori(n)	in(b[i]);
		
	fori(m)
	{
		in(x);	x--;
		in(y);	y--;
		cap X, Y;
		X.first = b[y];
		X.second= y;
		Y.first = b[x];
		Y.second= x;
		
		a[x].push(X);
		a[y].push(Y);
	}
	
	k--;
	fori(n)
	{
		if( a[i].size() <= k || a[i].empty() )	
			out((ll)-1);
		else
		{
			forj(k)	
				a[i].pop();
			out( a[i].top().second +1 );
		}
	}
}

