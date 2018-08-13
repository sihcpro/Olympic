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

char a[10][10];

int main()
{
	for0(i, 4)
		for0(j, 4)
			cin >> a[i][j];
	
	for0(i, 3)
		for0(j, 3)
		{
			x= 0;
			y= 0;
			for0(m, 2)
				for0(n, 2)
				{
					if( a[i+m][j+n] == '.' ) x++;
					if( a[i+m][j+n] == '#' ) y++;
				}
			if( x >= 3 || y >= 3 )
			{
				cout << "YES";
				return 0;
			}
		}
	cout << "NO";
	

	return 0;
}








