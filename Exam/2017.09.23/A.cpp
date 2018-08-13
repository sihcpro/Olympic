#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define fori(num) for(ll i= 0; i < num; i++)
#define forj(num) for(ll j= 0; j < num; j++)
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

int main()
{
	cin >> x >> y;
	
	y = max(x, y);
	
	switch( y )
	{
		case 1:
			cout << "1/1" << endl;
			return 0;
		case 2:
			cout << "5/6" << endl;
			return 0;
		case 3:
			cout << "2/3" << endl;
			return 0;
		case 4:
			cout << "1/2" << endl;
			return 0;
		case 5:
			cout << "1/3" << endl;
			return 0;
		case 6:
			cout << "1/6" << endl;
			return 0;
			
	}

	return 0;
}








