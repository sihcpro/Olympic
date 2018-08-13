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

string s1, s2;

long a[10], b[10];
int main()
{
	cin >> n;
	
	m= 0;
	for(int i= 1; i <= 9; i++)	
	{
		cin >> a[i];
		b[i]= n/a[i];
		if( m < b[i] )	m= b[i];
	}
	sp= -1;
	long Min= 0;
	for(int i= 9; i >= 1; i--)
	{
		if( sp < n- b[i]*a[i] && b[i] == m  )
		{
			sp= n- b[i]*a[i];
			Min= i;
		}
	}
	
	if( m == 0 )
		cout << -1;
	else
	{
//		cout << m << "   " << sp << "  " << Min << endl;
		int i= 9;
		while( sp > 0 && i > Min )
		{
			if( sp >= a[i] - a[Min] )
			{
				printf("%d", i);
				sp-= a[i] - a[Min];
				m--;
			}
			else
			{
				i--;
			}
		}
		for(int i= 0; i < m; i++)
		{
			printf("%d", Min);
		}
	}
	
	return 0;
}








