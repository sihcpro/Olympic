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
ll n= 0, k= 0, s;
string s1, s2;

int main()
{
	cin >> n >> m >> x >> y;
	
	ll lx = (x-1)/m;
	ll ly = (y-1)/m;
	ll rx = (x-1)%m;
	ll ry = (y-1)%m;

//	cout << lx << " " << ly << " " << rx << " " << ry << endl;
	if( (n == y && rx == 0) || m == 1 || lx == ly || (rx == 0 && ry == m-1) )
	{
		cout << 1;
		return 0;
	}
	
	if( n == y || ly - lx == 1 || rx == 0 || ry == m-1 || ry + 1 == rx ){
		cout << 2;
		return 0;
	}
	
	cout << 3;
	return 0;
}








