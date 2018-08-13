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

ll t, m, sp, junger, mid, top, bot, d, test;
ll n= 0, k= 0;
string s1, s2;

int main()
{
	cin >> test;
	
	while( test-- )
	{
		cin >> n >> m;
		
		int a[n+5];
		vector<ll> b;
		
		d= 0;
		ll ma= 0ll;
		for0(i, n)
		{
			scanf("%d", &a[i]);
			if( a[i] == m )
			{
//				if()
				b.push_back(d);
				d=0;
			}
			else if( a[i] < m )
			{
				b.push_back(d);
				d= 0;
//				cout << b.size()-1 << "  " << i << endl;
				for0(i, b.size()-1)
					ma= max(ma, b[i]+b[i+1]);				
				if( !b.empty() ) b.clear();
			}
			else
				d+= a[i];
		}
		b.push_back(d);		
		
		for0(i, b.size()-1)
			ma= max(ma, b[i]+b[i+1]);
			
		cout << ma+m << endl;
		if( !b.empty() ) b.clear();
	}
	
	return 0;
}








