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

ll s1, s2;

ll a[1005][1005];
ll b[1005][1005];

int main()
{
	cin >> n >> k;

	for(ll i= 1; i <= 1000; i++)	a[i][0]= 1;

	for(ll i= 1; i <= 1000; i++)
	{
		for(ll j= 1; j <= 1000; j++)
		{
			a[i][j]= ( a[i-1][j] + a[i][j-1] ) % mod;
			b[i][j]= ( b[i][j-1] + a[i][j]   ) % mod;
		}
	}
	
//	fori(10)
//	{
//		forj(10)	cout << b[i][j] << "  ";
//		cout << endl;
//	}
	
	cout << b[n][k];
}



