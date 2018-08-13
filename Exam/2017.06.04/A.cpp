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


int main()
{	
	cin >> k >> x >> y;

	top= y/k;
	bot= x/k;
	sp= ( x%k == 0 || x%k < 0 )?1:0;
	cout << top - bot + sp;
}

