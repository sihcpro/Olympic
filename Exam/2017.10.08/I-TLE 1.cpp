#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define for0(i, num) for(ll i= 0; i < num; i++)
#define for1(i, num) for(ll i= 1; i <= num; i++)
#define fordown(num) for(ll i= num-1; i >= 0; i--)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll t, m, sp, junger, mid, top, bot, x, y, d, test;
ll n= 0, k= 0;
string s1, s2;

struct num{
	ll n;
	ll vt;
	
	public:
	num()
	{
		n= 0;
		vt= 0;
	}
};
num a[100005];

bool pairnum(num n1, num n2)
{
	return (n1.n > n2.n );
}

int main()
{
	cin >> n >> m;
	
	for0(i, n)
	{
		scanf("%ld", &a[i].n);
		a[i].vt= i+1;
	}
	
	sort( a, a+n, pairnum );
	
//	for0(i, n)
//		cout << a[i].n << endl;

	for0(i, m)
	{
		cin >> x >> y >> k;
		d= 0;
		long j= 0;
		for(; j < n && d < k; j++)
			if( !( a[j].vt > y || a[j].vt < x ) ) d++;
		printf("%ld\n", a[j-1].n );
	}
	
	return 0;
}








