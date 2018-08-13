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

ll a[60005];

int main()
{
	cin >> n;

	s= 0;
	
	fori(n)
	{
		in(sp);
		
		m= 0;
		if( sp > 30000 )
		{
			for( ll j= sp+1; j <= 60000; j++)		m+= a[j];
//			cout << m <<  "  " << m << endl;
			s+= m;
		}
		else
		{
			for( ll j= 0; j <= sp; j++)			m+= a[j];
//			cout << m <<  "  " << i-m << endl;
			s+= (i-m);
		}
		a[sp]++;
	}
	
	cout << s;
}



