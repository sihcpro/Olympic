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

int ax[8] = {-1, -1, -1,  0,  1,  1,  1,  0};
int ay[8] = {-1,  0,  1,  1,  1,  0, -1, -1};

bool a[1005][1005] = {false};

void check(int x1, int y1)
{
	a[x1][y1] = false;
	for0(i, 8)
	{
		int xx= x1+ ax[i];
		int yy= y1+ ay[i];
		if( xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] )
		{
			check(xx, yy);
		}
	}
}

int main()
{
	cin >> n >> m;
	
	for0(i, n)
		for0(j, m)
		{
			char s;
			cin >> s;
			if( s == 'W' )
				a[i][j] = true;
		}
	
	d= 0;
	for0(i, n)
		for0(j, m)
			if( a[i][j] )
			{
				d++;
				check( i, j);
			}	
	
//	for0(i, n)
//	{
//		for0(j, m)
//			cout << a[i][j];
//		cout << endl;
//	}
	cout << d;
}








