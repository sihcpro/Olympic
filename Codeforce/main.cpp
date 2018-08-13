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


ll t, m, sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0;
ll test;
string s1, s2;

long a[100005];		//	cong cu
long b[100005];		//	thung
long c[100005];		//	thung chua trong dinh

long root(long i)
{
	return ( a[i] < 0 ) ? c[i] : ( a[i] = root( a[i] ) );
}

void merge(long x, long y)
{
	if( b[x] == -1 )	//	thung 1 trong
		return;
	
	long &dinh= b[x];
	long &dinh2= b[y];
	if( dinh2 == -1 )	//	thung 2 trong
	{
		dinh2= dinh;
		dinh= -1;
		c[dinh2]= y;
	}
	else				//	2 thung deu co
	{
		a[dinh]= dinh2;
		dinh= -1;
	}
}

int main()
{
	cin >> n >> m;
	
	for1(i, n){
		a[i]= -1;
		b[i]= i;
		c[i]= i;
	}
	
	for0(i, m)
	{
		in(x);
		in(y);
		merge(x, y);
	}
	
	for1(i, n)
		printf("%ld ", root( i ) );
	
	return 0;
}
