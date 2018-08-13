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
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0;
ll test;

ll a[2][100005];
ll b[100005];

void dp(ll i)
{
    a[0][i]= max( a[0][i-1], a[1][i-1]);
    a[1][i]= a[0][i-1] + b[i];
    if( i < n )	dp(i+1);
}

int main()
{
    cin >> test;

	forj(test)
	{
        cin >> n;
        fori(n)
        {
            in(b[i]);
		}

        dp(0);

        printf("Case %d: %I64d\n", j, max( a[0][n-1], a[1][n-1]) );
	}
}
